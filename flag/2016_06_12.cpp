#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
#define pub push_back
typedef pair < int, int > pii;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 105;
LL dp[maxn][2];
LL a[maxn], b[maxn];
int pre[maxn];
struct Edge{
    int v, next;
}E[maxn << 1];
int head[maxn], tol;
struct Node{
    int id, f;
    LL val;
    bool operator <(const Node& tmp) const{
        return val < tmp.val;
    }
}gao[maxn];

void init(){
    memset(head, -1, sizeof head);
    tol = 0;
}

void add_edge(int u, int v){
    E[tol].v = v;
    E[tol].next = head[u];
    head[u] = tol++;
}

void dfs(int u, int ppre){
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == ppre) continue;
        dfs(v, u);
    }
    int tol = 0, sz = 0;
    for(int i = head[u]; ~i; i = E[i].next){
        int v = E[i].v;
        if(v == ppre) continue;
        gao[tol].id = v;
        gao[tol].f = 0;
        gao[tol++].val = a[v];
        gao[tol].id = v;
        gao[tol].f = 1;
        gao[tol++].val = b[v];
        sz++;
    }
    if(!tol){
        dp[u][0] = a[u];
        dp[u][1] = b[u];
        return;
    }
    dp[u][0] = dp[u][1] = -INF;
    sort(gao, gao + tol);
    for(int i = tol - 1; i >= 0; i--){
        memset(pre, -1, sizeof pre);
        LL sum = 0, DP, fu, mx, mi; //枚举最大值
        int flag = gao[i].id, cnt = 0;
        for(int j = i; j >= 0; j--){
            if(j != i && gao[j].id == flag) continue;
            //枚举最小值
            int p = pre[gao[j].id];
            if(p != -1){
                DP = sum - dp[gao[p].id][gao[p].f] + dp[gao[j].id][gao[j].f];
                sum = max(sum, DP);
            }else{
                DP = sum + dp[gao[j].id][gao[j].f];
                sum = DP;
                cnt++;
            }
            pre[gao[j].id] = j;
            if(cnt == sz){
                mx = max(gao[i].val, a[u]);
                mi = min(gao[j].val, a[u]);
                fu = max((LL)ceil(1.0 * (mx - mi) / 1000.0) * 666 * u, 0LL);
                dp[u][0] = max(dp[u][0], a[u] + sum - fu);

                mx = max(gao[i].val, b[u]);
                mi = min(gao[j].val, b[u]);
                fu = max((LL)ceil(1.0 * (mx - mi) / 1000.0) * 666 * u, 0LL);
                dp[u][1] = max(dp[u][1], b[u] + sum - fu);
            }
        }
    }
}

int main(){
    int n, u, v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld", &a[i], &b[i]);
    }
    init();
    for(int i = 1; i < n; i++){
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, -1);
    printf("%lld\n", max(dp[1][0], dp[1][1]));
    return 0;
}
