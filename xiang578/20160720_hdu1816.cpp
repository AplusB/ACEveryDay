#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5000;
const int B=2;
const int W=1;
stack<int>st;
vector<int>g[N];
vector<int>gt[N];
int col[N],in[N],id[N],dfn[N],low[N],cnt,def,opp[N],n,m,mu[N],mv[N],num[N];
vector<int>gg[N];
void add(int u,int v)
{
    g[u].push_back(v);
}

void add2(int u,int v)
{
    gt[u].push_back(v);
}

void topsort()
{
    int u,v;
    queue<int>q;
    memset(col,0,sizeof(col));
    for(int i=1; i<=cnt; i++)
        if(!in[i]) q.push(i);
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(col[u]) continue;
        col[u]=W;
        col[opp[u]]=B;
        for(int i=0; i<gt[u].size(); i++)
        {
            v=gt[u][i];
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
}

void tarjan(int u)
{
    int k,mx=dfn[u]=low[u]=++def;
    st.push(u);
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(dfn[v]==-1) tarjan(v);
        if(low[v]<mx) mx=low[v];
    }
    if(mx<low[u])
    {
        low[u]=mx;
        return ;
    }
    cnt++;
    do
    {
        k=st.top();
        id[k]=cnt;
        low[k]=4*n;
        st.pop();
    }
    while(k!=u);
}

void init()
{
    for(int i=0; i<4*n; i++)
    {
        g[i].clear();
        gt[i].clear();
        id[i]=i;
        in[i]=0;
    }
    def=0;
    cnt=0;
    memset(dfn,0xff,sizeof(dfn));
    while(!st.empty()) st.pop();
}

int solve(int x)
{
    init();
    int u,v;
    for(int i=0;i<2*n;i++)
    {
        u=i*2;
        for(int j=0;j<gg[i].size();j++)
        {
            v=gg[i][j]*2;
            add(u,v^1);
            add(v,u^1);
        }
    }
    for(int i=0;i<x;i++)
    {
        int u=mu[i]*2;
        int v=mv[i]*2;
        add(u^1,v);
        add(v^1,u);
    }
    for(int i=0; i<4*n; i++)
        if(dfn[i]==-1) tarjan(i);
    bool ok=1;
    for(int i=0; i<2*n; i++)
    {
        if(id[i*2]==id[i*2+1])
        {
            ok=0;
            break;
        }
    }
    if(!ok)
        return 0;
    else
        return 1;
}

int main()
{
    int a,b,u,v,L,R,M,fu,fv;
    char s1[10],s2[10];
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(int i=0;i<2*n;i++)
        {
            gg[i].clear();
        }
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            gg[u].push_back(v);
            gg[v].push_back(u);
        }
        for(int i=0; i<m; i++)
            scanf("%d%d",&mu[i],&mv[i]);
        L=0;
        R=m;
        int ans=0;
        while(L<=R)
        {
            M=(L+R)/2;
            if(solve(M)==1)
            {
                ans=M;
                L=M+1;
            }
            else
                R=M-1;
        }
        printf("%d\n",ans);

    }
    return 0;
}
