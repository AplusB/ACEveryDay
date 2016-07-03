#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 205;
const int maxm = maxn * maxn;
struct Edge{
    int v, next, flow, cap;
}E[maxm << 1];
int head[maxn], tol;
int gap[maxn], dep[maxn], pre[maxn], cur[maxn];

void init(){
    memset(head, -1, sizeof head);
    tol = 0;
}

void add_edge(int u, int v, int cap, int rcap = 0){
    E[tol].v = v;
    E[tol].cap = cap;
    E[tol].flow = 0;
    E[tol].next = head[u];
    head[u] = tol++;

    E[tol].v = u;
    E[tol].cap = rcap;
    E[tol].flow = 0;
    E[tol].next = head[v];
    head[v] = tol++;
}

int isap(int Start, int End, int N){
    memset(gap, 0, sizeof gap);
    memset(dep, 0, sizeof dep);
    memcpy(cur, head, sizeof head);
    int u = Start;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[Start] < N){
        if(u == End){
            int Min = INF;
            for(int i = pre[u]; ~i; i = pre[E[i ^ 1].v])
                if(Min > E[i].cap - E[i].flow)
                    Min = E[i].cap - E[i].flow;
            for(int i = pre[u]; ~i; i = pre[E[i ^ 1].v]){
                E[i].flow += Min;
                E[i ^ 1].flow -= Min;
            }
            u = Start;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; ~i; i = E[i].next){
            v = E[i].v;
            if(E[i].cap - E[i].flow && dep[v] + 1 == dep[u]){
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag){
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; ~i; i = E[i].next){
            if(E[i].cap - E[i].flow && dep[E[i].v] < Min){
                Min = dep[E[i].v];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != Start) u = E[pre[u] ^ 1].v;
    }
    return ans;
}

vector < int > res, ans[2];
int a, b, mid;
void dfs(int u, int flag){
    res.push_back(u / 2);
    if(u / 2 == a || u / 2 == b){
        if(u / 2 == a){
            for(int i = res.size() - 1; i >= 0; i -= 2){
                ans[0].push_back(res[i]);
            }
            ans[0].push_back(mid);
        }else{
            for(int i = 0; i < res.size(); i += 2){
                ans[1].push_back(res[i]);
            }
        }
        return;
    }
    for(int i =  head[u]; ~i; i = E[i].next){
        if(E[i].flow >= 1){
            if(!flag) res.clear();
            dfs(E[i].v, flag | 1);
        }
    }
}

int main(){
    int T, n, m, x, y;
    scanf("%d", &T);
    while(T--){
        init();
        scanf("%d%d", &n, &m);
        scanf("%d%d%d", &a, &b, &mid);
        for(int i = 1; i <= n; i++){
            if(i != mid)
                add_edge(i << 1, i << 1 | 1, 1);
            else
                add_edge(i << 1, i << 1 | 1, 2);
        }
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &x, &y);
            add_edge(x << 1 | 1, y << 1, INF);
            add_edge(y << 1 | 1, x << 1, INF);
        }
        int s = (n + 1) * 2, t = s + 1;
        add_edge(s, mid << 1, 2);
        add_edge(a << 1 | 1, t, 1);
        add_edge(b << 1 | 1, t, 1);
        isap(s, t, t);
        ans[0].clear();
        ans[1].clear();
        dfs(mid << 1 | 1, 0);
        for(int f = 0; f < 2; f++)
        for(int i = 0; i < ans[f].size(); i++){
            printf("%d%c", ans[f][i], f && i == ans[f].size() - 1 ? '\n' : ' ');
        }
    }
	return 0;
}
