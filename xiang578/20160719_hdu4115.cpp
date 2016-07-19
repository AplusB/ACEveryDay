#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=20000+10;
const int B=2;
const int W=1;
stack<int>st;
vector<int>g[N];
vector<int>gt[N];
int col[N],in[N],id[N],dfn[N],low[N],cnt,def,opp[N],n,m,A[N],D[N];

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
    int _,a,b,u,v,k,cas=0;
    int ok;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        init();
        ok=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",A+i);
            if(A[i]==1)
            {
                D[i*2]=1;
                D[i*2+1]=2;
            }
            if(A[i]==2)
            {
                D[i*2]=2;
                D[i*2+1]=3;
            }
            if(A[i]==3)
            {
                D[i*2]=3;
                D[i*2+1]=1;
            }
        }
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d",&a,&b,&k);
            a--;
            b--;
            if(ok==0) continue;
            if(a==b)
            {
                if(k==1) ok=0;
                continue;
            }
            int wa=D[a*2+1];
            int wb=D[b*2+1];
            int la=D[a*2];
            int lb=D[b*2];
            if(k)
            {
                if(wa==wb)
                {
                    add(a*2+1,b*2);
                    add(b*2+1,a*2);
                }
                if(wa==lb)
                {
                    add(a*2+1,b*2+1);
                    add(b*2,a*2);
                }
                if(la==wb)
                {
                    add(a*2,b*2);
                    add(b*2+1,a*2+1);
                }
                if(la==lb)
                {
                    add(a*2,b*2+1);
                    add(b*2,a*2+1);
                }
            }
            else
            {
                /*if(wa==wb)
                {
                    add(a*2+1,b*2+1);
                    add(b*2+1,a*2+1);
                }
                if(wa==lb)
                {
                    add(a*2+1,b*2);
                    add(b*2,a*2+1);
                }
                if(la==wb)
                {
                    add(a*2,b*2+1);
                    add(b*2+1,a*2);
                }
                if(la==lb)
                {
                    add(a*2,b*2);
                    add(b*2,a*2);
                }*/
                if(wa!=wb)
                {
                    add(a*2+1,b*2);
                    add(b*2+1,a*2);
                }
                if(wa!=lb)
                {
                    add(a*2+1,b*2+1);
                    add(b*2,a*2);
                }
                if(la!=wb)
                {
                    add(a*2,b*2);
                    add(b*2+1,a*2+1);
                }
                if(la!=lb)
                {
                    add(a*2,b*2+1);
                    add(b*2,a*2+1);
                }
            }
        }

        if(ok)
        {
            for(int i=0; i<2*n; i++)
                if(dfn[i]==-1) tarjan(i);
            for(int i=0; i<n; i++)
            {
                if(id[i*2]==id[i*2+1])
                {
                    ok=0;
                    break;
                }
            }
        }
        if(!ok)
            printf("Case #%d: no\n",++cas);
        else
            printf("Case #%d: yes\n",++cas);
    }
    return 0;
}
