#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N ((1<<13) + 10)
int n, a[N], idx[N], h[N];
char s[N];
short dp[N][N];

int highb(int v) {
    if (!v) return 0;
    int res = 0;
    while ((v >> 1) > 0){
        v >>= 1;
        res++;
    }
    return (1 << res);
}

pii calc_nxt(int l, int r) {
    int hl = h[l];
    int hr = h[r];
    if (hl <= hr) {
        return make_pair(l + hr, r - hr);
    } else return make_pair(l, r);
}

string bin(int v) {
    if (!v) return "0";
    string res = "";
    while (v) {
        res += (v & 1) + '0';
        v >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

void debug(int l, int r, pii nxt) {
    printf("l:%d(%s) r:%d(%s) nxt(%d(%s), %d(%s))\n",
            l, bin(l).c_str(),
            r, bin(r).c_str(),
            nxt.first, bin(nxt.first).c_str(),
            nxt.second, bin(nxt.second).c_str());
}

bool dfs(int l, int r) {
    int id = idx[l + r];

    if (id == n) {
        if (l == 0) return dp[l][r] = 1;
        if (r == 0) return dp[l][r] = 1;
        return dp[l][r] = 0;
    }

    if (dp[l][r] != -1) return dp[l][r];
    bool res = 0;
    if (l == 0 || a[id] <= LOWB(l)) {
        pii nxt = calc_nxt(l + a[id], r);
        //debug(l, r, nxt);
        if (dfs(nxt.first, nxt.second)) {
            res = 1;
            s[id] = 'l';
        }
        if (res) return dp[l][r] =res;
    }
    if (r == 0 || a[id] <= LOWB(r)) {
        pii nxt = calc_nxt(l, r + a[id]);
        //debug(l, r, nxt);
        if (dfs(nxt.first, nxt.second)) {
            res = 1;
            s[id] = 'r';
        }
        if (res) return dp[l][r] = res;
    }
    return dp[l][r] = res;
}

bool check() {
    int l = 0, r = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'l') {
            if (l == 0 || LOWB(l) >= a[i]) l += a[i];
            else return false;
        } else {
            if (r == 0 || LOWB(r) >= a[i]) r += a[i];
            else return false;
        }
        if (h[l] <= h[r]) {
            int x = h[r];
            l += x;
            r -= x;
        }
    }
    return r == 0;
}

void solve(int tot) {
    for (int i=0; i<=tot; i++)
        for (int j=0; j<=tot; j++) dp[i][j] = -1;
    dfs(0, 0);
    if (dp[tot][0] == 1 || dp[0][tot] == 1) {
        s[n] = 0;
        assert(check());
        printf("%s\n", s);
    } else printf("no\n");
}

void do_case() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    int sum = 0;
    for (int i=0; i<n; i++) {
        idx[sum] = i;
        sum += a[i];
    }
    idx[sum] = n;
    int tmp = sum;
    while (tmp) {
        if (!(tmp & 1))tmp >>= 1;
        else break;
    }
    if (tmp != 1) printf("no\n");
    else solve(sum);
}

void init() {
    for (int i=0; i<N; i++) h[i] = highb(i);
}

int main() {
    //freopen("test.in", "r", stdin);
    int cas;
    init();
    cin >> cas;
    while (cas--) do_case();
    return 0;
}
