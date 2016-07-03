#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

#define FREAD(fn) freopen((fn), "r", stdin)
#define RINT(vn) scanf("%d", &(vn))
#define PINT(vb) printf("%d", vb)
#define RSTR(vn) scanf("%s", (vn))
#define PSTR(vn) printf("%s", (vn))
#define CLEAR(A, X) memset(A, X, sizeof(A))
#define REP(N) for(i=0; i<(N); i++)
#define REPE(N) for(i=1; i<=(N); i++)
#define pb(X) push_back(X)
#define pn() printf("\n")
using namespace std;
const int MAX_N = 100005;
int i, j;
int n;
int a[MAX_N], b[MAX_N], c[MAX_N];

int main()
{
	FREAD("519b.txt");
	RINT(n);
	REP(n) RINT(a[i]);
	REP(n-1) RINT(b[i]);
	REP(n-2) RINT(c[i]);
	sort(a, a+n);
	sort(b, b+n-1);
	sort(c, c+n-2);
	REP(n){
		if(i == n-1 || a[i] != b[i]){
			PINT(a[i]); pn();
			break;
		}
	}
	REP(n-1){
		if(i == n-2 || b[i] != c[i]){
			PINT(b[i]); pn();
			break;
		}
	}
	return 0;
}
