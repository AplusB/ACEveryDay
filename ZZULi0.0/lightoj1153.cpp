#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 105;
int maze[N][N],n;
bool visit[N];
 
 
int dfs(int s,int t,int f)
{
    if(s == t) return f;
    visit[s] = true;
    for(int i = 1; i <= n; i++)
    {
        if(maze[s][i] != 0)
        {
            int &tmp = maze[s][i];
            if(visit[i] == false && tmp > 0)
            {
                int d = dfs(i,t,min(f,tmp));
                if(d > 0)
                {
                    tmp -= d;
                    maze[i][s] += d;
                    return d;
                }
            }
        }
 
    }
    return 0;
}
 
int max_flow(int s,int t)
{
    int flow = 0;
    for(;;)
    {
        memset(visit,false,sizeof(visit));
        int f = dfs(s,t,INT_MAX);
        if(f == 0)
            return flow;
        flow += f;
    }
}
 
void solve()
{
    int m,s,d;
 
    scanf("%d",&n);
    scanf("%d %d %d",&s,&d,&m);
    memset(maze,0,sizeof(maze));
    for(int i = 0 ; i < m; i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        maze[u][v] += w;
        maze[v][u] += w;
    }
    printf("%d\n",max_flow(s,d));
}
 
int main()
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
