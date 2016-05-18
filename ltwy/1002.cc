#include <bits/stdc++.h>
using namespace std;
int T;
int g[510][510];
int n,m;
const int INF = 0x3f3f3f3f;
int Scan() {    
    int res = 0, flag = 0;
    char ch;
    if((ch = getchar()) == '-') flag = 1;
    else if(ch >= '0' && ch <= '9') res = ch - '0';
    while((ch = getchar()) >= '0' && ch <= '9')
        res = res * 10 + (ch - '0');
    return flag ? -res : res;
}
int dis[510];
bool vis[510];
void Dijkstra(int st) {
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    dis[st] = 0;
    for(int i=0; i<n; i++) {
        int flag = -1;
        int Min = INF;
        for(int j=0; j<n; j++)
            if(!vis[j] && dis[j] != -1 && dis[j] < Min) {
                Min = dis[j];
                flag = j;
            }
        if(flag == -1) break;
        vis[flag] = true;
        for(int j=0; j<n; j++) {
            if(g[flag][j] != -1) {
                if(dis[j] == -1)
                    dis[j] = max(Min, g[flag][j]);
                else
                    dis[j] = min(dis[j], max(Min, g[flag][j]));
            }
        }
    }
}
 
int t;
int main() {
    cin>>T;
    for(int icase = 1; icase<=T; icase++) {
        memset(g, -1, sizeof(g));
        cin>>n>>m;
        int u,v,w;
        for(int i=0; i<n; i++)
            g[i][i] = 0;
        for(int i=1; i<=m; i++) {
            u = Scan(); v = Scan(); w = Scan();
            if(g[u][v] == -1)
                g[u][v] = g[v][u] = w;
            else
                g[v][u] = g[u][v] = min(g[u][v], w);
        }
        cin>>t;
        Dijkstra(t);
        printf("Case %d:\n", icase);
        for(int i=0; i<n; i++)
            if(dis[i] == -1)
                puts("Impossible");
            else
                printf("%d\n", dis[i]);
    }
    return 0;
}