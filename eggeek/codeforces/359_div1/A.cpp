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
ll n, m, cn[1<<7], cm[1<<7];
int p[1<<7];

int dfs(int msk, int tot, int big) {
    if (msk == 0) return tot < big;
    int res = 0;
    int tmp = msk;
    while (tmp) {
        int c = LOWB(tmp);
        int nxt = tot * 7 + p[c];
        if (nxt < big)
            res += dfs(msk - c, nxt, big);
        tmp -= c;
    }
    return res;
}

int cnt_bit(int v, int base) {
    if (!v) return 1;
    int res = 0;
    while (v) {
        v /= base;
        res++;
    }
    return res;
}

int cnt_one(int v) {
    int res = 0;
    while (v) {
        res++;
        v -= LOWB(v);
    }
    return res;
}

bool valid(int msk, int big) {
    if (cnt_bit(big-1, 7) != cnt_one(msk)) return false;
    return true;
}

void init() {
    for (int i=0; i<7; i++) p[1 << i] = i;
    for (int msk=1; msk < (1<<7); msk++) {
        if (valid(msk, n))
            cn[msk] = dfs(msk, 0, n);
        if (valid(msk, m))
            cm[msk] = dfs(msk, 0, m);
    }
}

ll calc() {
    ll ans = 0;
    for (int msk=1; msk < (1<<7); msk++) {
        for (int sub=msk; sub; sub = msk & (sub - 1)) {
            ans += cn[sub] * cm[msk-sub];
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    init();
    ll ans = calc();
    cout << ans << endl;
    return 0;
}
