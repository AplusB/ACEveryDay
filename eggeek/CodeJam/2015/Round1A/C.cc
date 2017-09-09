#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
# define x real ()
# define y imag ()
# define cpt const Pt&
#define N 16
int n, bcnt[1<<N];

const double EPS = 1e-9;
const double pi = acos(-1);
const double inf = 1e100;
bool deq(double a, double b) {return (fabs(a-b)) < EPS;}

typedef complex<double> cpx;
struct Pt : cpx {
  public:
    int id;
  Pt() = default; using cpx::cpx;
  Pt(cpx a) : cpx(a) {}
  double& x const { return (double&)*this;}
  double& y const { return ((double*)this)[1];}
  bool operator ==(cpt b) const { return abs(*this-b) < EPS;}
  bool operator <(cpt b) const { return x < b.x || (x == b.x && y<b.y); }
};

double det(cpt a, cpt b) { return (conj(a) * b).y;}
bool epsless ( cpt a , cpt b) { return a.x+ EPS <b .x || ( deq ( a.x ,b .x) && a.y < b.y) ;}
bool collinear(Pt a, Pt b, Pt c) { return deq(det(b-a, c-b), 0); }

vector<Pt> convexhull(vector<Pt> p) {
  sort(p.begin(), p.end(), epsless);
  p.resize(unique(p.begin(), p.end())-p.begin());
  int l=0, u=0; vector<Pt> L(p), U(p);
  if (p.size() <= 2) return p;
  for (Pt& i: p) {
    while (l>1 && det(i-L[l-1], L[l-2]-i)<-EPS) l--;
    while (u>1 && det(i-U[u-1], U[u-2]-i)>EPS) u--;
    L[l++] = U[u++] = i;
  }
  L.resize(l+u-2);
  for (int i=1; i<u-1; i++) L[l++] = U[u-i-1]; 
  return L;
}

vector<Pt> ps;

int mindel_sml(int id) {
  int ans = n-1;
  for (int i=0; i<(1<<n); i++) if (i & (1<<id)) {
    if (bcnt[i] <= 2) ans = min(ans, n-bcnt[i]); 
    else {
      vector<Pt>tmp;
      for (int j=0; j<n; j++) if (i & (1<<j)) tmp.push_back(ps[j]);
      vector<Pt> L = convexhull(tmp);
      /*
      if (i == (1<<n)-1) {
        printf("tmp: ");
        for (int k=0; k<(int)tmp.size(); k++) printf("%d ", tmp[k].id);
        printf("\nL: ");
        for (int k=0; k<(int)L.size(); k++) printf("%d ", L[k].id);
        printf("\n");
      }
      */
      for (int k=0; k<(int)L.size(); k++) {
        Pt u = L[k];
        Pt v = L[(k+1) % (int)L.size()];
        if (collinear(u, v, ps[id])) {
          ans = min(ans, n - bcnt[i]);
        }
      }
    }
  }
  return ans;
}

double dgr(double rad) {
  return rad * 180.0 / pi;
}

int mindel_large(int i) {
  int ans = n;
  if (n <= 3) return 0;
  vector<double> angles;
  for (int j=0; j<n; j++) if (j != i) {
    angles.push_back(dgr(atan2(ps[j].x - ps[i].x, ps[j].y - ps[i].y)));
  }
  for (int j=0; j<(int)angles.size(); j++) if (angles[j] < 0) angles[j] += 360.0;
  sort(angles.begin(), angles.end());
  int m = (int)angles.size();

  /*
  printf("id: %d, angles: ", i);
  for (int j=0; j<m; j++) printf("%lf ", angles[j]);
  printf("\n");
  */
  for (int j=0; j<m; j++) angles.push_back(angles[j] + 360.0);
  int r = 0, l = 0;
  for (l=0; l<m; l++) {
    while (r+1 < 2*m && r+1-l+1<=m && angles[r+1] - angles[l] <= 180.0) r++;
    int sz = r - l + 2;
    ans = min(ans, min(n-sz, sz-1));
  }
  return ans;
}

void do_case(int cas) {
  cin >> n;
  ps.resize(n);
  for (int i=0; i<n; i++) {
    int xx, yy;
    cin >> xx >> yy;
    ps[i] = Pt((double)xx, (double)yy);
    ps[i].id = i;
  }


  for (int i=0; i<n; i++) {
    //int ans = mindel_sml(i);
    int ans = mindel_large(i);
    printf("%d\n", ans);
  }
}


int main() {
  init_bcnt();
  int cas;
  cin >> cas;
  for (int i=1; i<=cas; i++) {
    printf("Case #%d:\n", i);
    do_case(i);
  }
  return 0;
}
