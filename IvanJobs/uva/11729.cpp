#include <bits/stdc++.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

using namespace std;

#define MAXN 1100

pair<int, int> H[MAXN];

bool cmp(pair<int, int> v1, pair<int, int> v2) {
    if (v1.second >= v2.second) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int t = 0;
    while (N != 0) {
        t++; // case index
        REP(i, N) {
            scanf("%d%d", &(H[i].first), &(H[i].second));
        }

        sort(H, H + N, cmp);

        int prefix_sum = 0;
        int res = 0;
        REP(i, N) {
            prefix_sum += H[i].first;
            res = max(res, prefix_sum + H[i].second);
        }
        printf("Case %d: %d\n", t, res);
        scanf("%d", &N);
    }
    return 0;
}
