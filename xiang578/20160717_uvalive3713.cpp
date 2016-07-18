#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=2*(100000+5);
const int B=2;
const int W=1;
stack<int>st;
vector<int>g[N];
vector<int>gt[N];
int col[N],in[N],id[N],dfn[N],low[N],cnt,def,opp[N],n,m;
double old[N],ave;
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
    int a,b,u,v,c1,c2;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        init();
        ave=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf",&old[i]);
            ave+=old[i];
        }
        ave/=n;
        //printf("%lf\n",ave);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d",&a,&b);
            a--;
            b--;
            if(old[a]>=ave) c1=0;
            else c1=1;
            if(old[b]>=ave) c2=0;
            else c2=1;
            if(c1==c2)
            {
                add(2*a,2*b+1);
                add(2*a+1,2*b);
                add(2*b,2*a+1);
                add(2*b+1,2*a);
            }
            else
            {
                add(2*a,2*b+1);
                add(2*b,2*a+1);
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
        {
            puts("No solution.");
            continue;
        }
        for(int i=0; i<n; i++)
        {
            opp[id[i*2]]=id[i*2+1];
            opp[id[i*2+1]]=id[i*2];
        }
        for(int i=0; i<2*n; i++)
        {
            u=id[i];
            for(int j=0; j<g[i].size(); j++)
            {
                v=id[g[i][j]];
                if(u==v) continue;
                add2(v,u);
                in[u]++;
            }
        }
        topsort();
        for(int i=0; i<2*n; i+=2)
        {
            if(col[id[i]]==W) printf("C\n");
            else
            {
                if(old[i/2]>=ave)
                    printf("A\n");
                else
                    printf("B\n");
            }
        }
    }
    return 0;
}
