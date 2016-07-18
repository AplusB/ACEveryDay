#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=2048;
const int B=2;
const int W=1;
stack<int>st;
vector<int>g[N];
vector<int>gt[N];
int col[N],in[N],id[N],dfn[N],low[N],cnt,def,opp[N],n,m;
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
        low[k]=2*n;
        st.pop();
    }
    while(k!=u);
}

void init()
{
    for(int i=0; i<2*n; i++)
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

int main()
{
    int a,b,u,v;
    char s1[10],s2[10];
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=0; i<m; i++)
        {
            scanf("%s%s",s1,s2);
            if(s1[0]=='+') a=0;
            else a=1;
            u=0;
            int len1=strlen(s1);
            for(int j=1;j<len1;j++)
                u=u*10+(s1[j]-'0');

            if(s2[0]=='+') b=0;
            else b=1;
            v=0;
            int len2=strlen(s2);
            for(int j=1;j<len2;j++)
                v=v*10+(s2[j]-'0');
            u--;
            v--;
            if(!a&&!b)
            {
                add(2*u,2*v+1);
                add(2*v,2*u+1);
            }
            if(a&&b)
            {
                add(2*v+1,2*u);
                add(2*u+1,2*v);
            }
            if(!a&&b)
            {
                add(2*u,2*v);
                add(2*v+1,2*u+1);
            }
            if(a&&!b)
            {
                add(2*v,2*u);
                add(2*u+1,2*v+1);
            }
        }

        for(int i=0; i<2*n; i++)
            if(dfn[i]==-1) tarjan(i);
        bool ok=1;
        for(int i=0; i<n; i++)
        {
            if(id[i*2]==id[i*2+1])
            {
                ok=0;
                break;
            }
        }
        if(!ok)
            puts("0");

        else
            puts("1");
    }
    return 0;
}
