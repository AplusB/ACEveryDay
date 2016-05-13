//http://begin.lydsy.com/JudgeOnline/problem.php?id=2604

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

const int N = 300010;
const int MAXM = 300010;
const int INF = 0x3f3f3f3f;

int dist[N<<1],mx[N],my[N],m,n;
vector<int> mp[N];
int que[N<<1],head,tail;
int bfs()
{
    int i;
    head=0;
    tail=-1;
    for(i=1; i<=n; i++)
        if(mx[i]==-1) que[++tail]=i;
    for(i=0; i<=m+n; i++) dist[i]=0;
    int flag=0;
    while(head<=tail)
    {
        int u=que[head++];
        for(i=0; i<mp[u].size(); i++)
        {
            int v=mp[u][i];
            if(dist[n+v]==0)
            {
                dist[n+v]=dist[u]+1;
                if(my[v]!=-1)
                {
                    dist[my[v]]=dist[n+v]+1;
                    que[++tail]=my[v];
                }
                else flag=1;
            }
        }
    }
    return flag;
}
int dfs(int u)
{
    for(int i=0; i<mp[u].size(); i++)
    {
        int v=mp[u][i];
        if(dist[u]+1==dist[v+n])
        {
            int t=my[v];
            dist[v+n]=0;
            if(t==-1||dfs(t))
            {
                my[v]=u;
                mx[u]=v;
                return 1;
            }
        }
    }
    return 0;
}
int H_K()
{
    int i;
    for(i=0; i<=n; i++)
        mx[i]=-1;
    for(i=0; i<=m; i++)
        my[i]=-1;
    int ans=0;
    while(bfs())
    {
        for(i=1; i<=n; i++)
            if(mx[i]==-1&&dfs(i)) ans++;
    }
    return ans;
}

template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
inline void out(int x)
{
    if(x>9) out(x/10);
    putchar(x%10+'0');
}

int main()
{
    //int n,m;
    //scanf("%d%d",&n,&m);
    scan_d(n);
    scan_d(m);
    int u,v;
    for(int i=0; i<m; ++i)
    {
        //scanf("%d%d",&u,&v);
        scan_d(u);
        scan_d(v);
        mp[u].push_back(v);
    }

    printf("%d\n",n-H_K());

    return 0;
}
