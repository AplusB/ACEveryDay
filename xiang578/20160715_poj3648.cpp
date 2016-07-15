#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int N=2*(16000+5);
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
    //两倍的点
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
    char c1,c2;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        if(n==0&&m==0) break;
        for(int i=0; i<m; i++)
        {
            scanf("%d%c%d%c",&a,&c1,&b,&c2);
            if(c1=='h') u=2*a;
            else u=2*a+1;
            if(c2=='h')v=2*b;
            else v=2*b+1;
            add(u,v^1);
            add(v,u^1);
        }
        add(1,0);//必须新郎
        //求强连通分量
        for(int i=0; i<2*n; i++)
            if(dfn[i]==-1) tarjan(i);
        //判断有无接
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
            puts("bad luck");
            continue;
        }
        //保存矛盾
        for(int i=0; i<n; i++)
        {
            opp[id[i*2]]=id[i*2+1];
            opp[id[i*2+1]]=id[i*2];
        }
        //缩点，反向建边
        for(int i=0; i<2*n; i++)
        {
            u=id[i];
            for(int j=0; j<g[i].size(); j++)//注意是原图i的边不是u的边
            {
                v=id[g[i][j]];
                if(u==v) continue;
                add2(v,u);
                in[u]++;
            }
        }
        //拓扑排序染色
        topsort();
        for(int i=2;i<2*n;i+=2)
        {
            if(i!=2) printf(" ");
            if(col[id[i]]==B) printf("%dh",i/2);
            else printf("%dw",i/2);
        }
        printf("\n");
    }
    return 0;
}
