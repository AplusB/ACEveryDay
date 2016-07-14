#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
const int MAXP = 18;

int f[MAXP][N], g[MAXP][N];
int n, a[N], b[N];

void RmqInit(int num[], int dp[][N], bool flag)
{
    for(int i = 0; i < n; i++) {
        dp[0][i] = num[i];
    }
    for(int j = 1; j < MAXP; j++) {
        int lim = n - (1 << j) ;
        for(int i = 0; i <= lim; i++) {
            if(flag)
                dp[j][i] = std::max(dp[j-1][i], dp[j-1][i+(1<<j>>1)]);
            else 
                dp[j][i] = std::min(dp[j-1][i], dp[j-1][i+(1<<j>>1)]);
        }
    }
}

int Log[N];
int Rmq(int dp[][N], bool flag, int L, int R)
{
    int m = Log[R - L + 1];
    if(flag)
        return std::max(dp[m][L], dp[m][R - (1<<m) + 1]);
    else
        return std::min(dp[m][L], dp[m][R - (1<<m) + 1]);
}

int main()
{
    Log[0] = -1;
    for(int i = 1; i < N; i++) {
        Log[i] = Log[i>>1] + 1;
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    RmqInit(a, f, true);
    RmqInit(b, g, false);
    long long ret = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > b[i]) {
            continue;
        }

        int l = 0, r = n - i - 1, best1 = -1;
        while(l <= r) {
            int m = l + r >> 1;
            int max_val = Rmq(f, true, i, i + m);
            int min_val = Rmq(g, false,i, i + m);
            if(max_val >= min_val) {
                if(max_val == min_val) {
                    best1 = m;
                }
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        l = 0; r = n - i - 1;
        int best2 = -1;
        while(l <= r) {
            int m = l + r >> 1;
            int max_val = Rmq(f, true, i, i + m);
            int min_val = Rmq(g, false, i, i + m);
            if(max_val <= min_val) {
                best2 = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if(best1 != -1) ret += best2 - best1 + 1;
    }
    printf("%lld\n", ret);
    return 0;
}
