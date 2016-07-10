#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e15;
const int maxn = 4005;
int t[maxn], p[maxn];
LL dp[2][maxn][2], g[maxn][2];
LL L1[maxn][2], L2[maxn][2];
LL R1[maxn][2], R2[maxn][2];

void cmin(LL &a, LL b){
    if(a > b) a = b;
}

LL toLeft(int l, int r, int f){
    if(l > r) return 0;
    return (L1[r][f] - L1[l - 1][f]) - (L2[r][f] - L2[l - 1][f]) * (l - 1);
}

LL toRight(int l, int r, int f){
    if(l > r) return 0;
    return (R2[r][f] - R2[l - 1][f]) * (r + 1) - (R1[r][f] - R1[l - 1][f]);
}

int main(){
    int T, N;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &N);
        for(int i = 1; i <= N; i++){
            scanf("%d%d", &t[i], &p[i]);
            L1[i][0] = L1[i - 1][0] + (LL)i * t[i];
            L2[i][0] = L2[i - 1][0] + t[i];
            L1[i][1] = L1[i - 1][1] + (LL)i * p[i];
            L2[i][1] = L2[i - 1][1] + p[i];

            R1[i][0] = R1[i - 1][0] + (LL)i * t[i];
            R2[i][0] = R2[i - 1][0] + t[i];
            R1[i][1] = R1[i - 1][1] + (LL)i * p[i];
            R2[i][1] = R2[i - 1][1] + p[i];
        }
        for(int i = 0; i < 2; i++)
            for(int j = 0; j <= N; j++)
                dp[i][j][0] = dp[i][j][1] = INF;
        for(int i = 0; i <= N; i++)
            g[i][0] = g[i][1] = INF;
        int now = 0, pre = 1;
        for(int i = 2; i <= N; i++){
            now ^= 1, pre ^= 1;
            for(int j = 0; j <= N; j++)
                dp[now][j][0] = dp[now][j][1] = INF;
            cmin(dp[now][i - 1][0], toRight(1, i - 1, 0) + p[i]);
            cmin(dp[now][i - 1][1], toRight(1, i - 1, 1) + t[i]);
            for(int j = 1; j < i - 1; j++){
                cmin(dp[now][j][0], dp[pre][j][0] + (LL)p[i] * (i - j));
                cmin(dp[now][j][1], dp[pre][j][1] + (LL)t[i] * (i - j));
                int mid = (j + i) >> 1;
                cmin(dp[now][i - 1][1], g[j + 1][0] + toLeft(j + 1, mid, 1) + toRight(mid + 1, i - 1, 1) + t[i]);
                cmin(dp[now][i - 1][0], g[j + 1][1] + toLeft(j + 1, mid, 0) + toRight(mid + 1, i - 1, 0) + p[i]);
            }
            cmin(g[i][0], dp[now][i - 1][0] - p[i]);
            cmin(g[i][1], dp[now][i - 1][1] - t[i]);
        }
        LL ans = INF;
        for(int i = 1; i < N; i++){
            cmin(ans, dp[now][i][0]);
            cmin(ans, dp[now][i][1]);
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}
/*
7
4
10 9
3 9
4 5
12 8

4
10 9
3 9
1 50
1 50

4
1 50
1 60
1 30
9 3

3
2 50
50 2
2 50

2
1 1
10 5

6
50 1
50 1
1 50
1 50
50 1
50 1

5
50 25
25 50
25 50
25 50
50 25
*/
