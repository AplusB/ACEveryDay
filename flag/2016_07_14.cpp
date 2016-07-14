#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
struct Edge{
    int u, v, len;
    bool operator<(const Edge& tmp) const{
        return len < tmp.len;
    }
}e[maxn];
int dp[maxn], g[maxn];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].len);
    }
    sort(e, e + m);
    e[m].len = 1e9 + 1;
    int last = -1;
    for(int i = 0; i < m; i++){
        if(e[i].len < e[i + 1].len){
            for(int j = last + 1; j <= i; j++){
                g[e[j].u] = dp[e[j].u];
                g[e[j].v] = dp[e[j].v];
            }
            for(int j = last + 1; j <= i; j++){
                dp[e[j].u] = max(dp[e[j].u], g[e[j].v] + 1);
                dp[e[j].v] = max(dp[e[j].v], g[e[j].u] + 1);
            }
            last = i;
        }
    }
    printf("%d\n", *max_element(dp, dp + n));
    return 0;
}
