#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
#define B(x) (1 << (x))
const int maxn = 20;
const int INF = 1e9 + 9e8;
int a[20], p[20], x;
int dp[B(19) + 5][20];
//vector < int >　p[maxn];

int bit_count(int st){
    int cnt = 0;
    while(st){
        cnt += (st & 1);
        st >>= 1;
    }
    return cnt;
}

int main(){
    int T, n;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        memset(p, -1, sizeof p);
        for(int i = 0; i < n; i++){
            scanf("%d%d", &a[i], &x);
            if(x != -1) p[x] = i;
        }
        p[n] = -1;
        int full = B(n) - 1;
        for(int s = 0; s <= full; s++)
            for(int i = 0; i <= n; i++)
                dp[s][i] = -INF;
        if(p[0] != -1){
            dp[B(p[0])][p[0]] = 0;
        }else{
            for(int i = 0; i < n; i++){
                dp[B(i)][i] = 0;
            }
        }
        for(int s = 0; s <= full; s++){
            int k = bit_count(s);
            for(int i = 0; i < n; i++)if(dp[s][i] != -INF){
                if(p[k] != -1){
                    if(s & B(p[k])) continue;
                     int nxt = s | B(p[k]), val = a[i] * a[p[k]];
                    dp[nxt][p[k]] = max(dp[nxt][p[k]], dp[s][i] + val);
                }else{
                    for(int j = 0; j < n; j++)if(!(s & B(j))){
                        int nxt = s | B(j), val = a[i] * a[j];
                        dp[nxt][j] = max(dp[nxt][j], dp[s][i] + val);
                    }
                }
            }
        }
        int ans = -INF;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[full][i]);
        }
        printf("Case #%d:\n%d\n", cas, ans);
    }
    return 0;
}
