#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <climits>
#define LL long long
using namespace std;
const int N = 1e5+5;
int head[N],tot;
int Low[N],DFN[N],Stack[N],Index,top,bridge;
bool Instack[N],cut[N];
struct nodes
{
    int next,to,cut;
} Edge[N*2];
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void add(int u,int v)
{
    Edge[tot].to = v;
    Edge[tot].next = head[u];
    head[u] = tot++;
    Edge[tot].cut = false;
}

void Tarjan(int u,int pre)
{
    int v;
    Low[u] = DFN[u] = ++Index;
    Stack[top++] = u;
    Instack[u] = true;
    int son = 0;
    for(int i = head[u]; i != -1; i = Edge[i].next)
    {
        v = Edge[i].to;
        if(v == pre) continue;
        if(!DFN[v])
        {
            son++;
            Tarjan(v,u);
            if(Low[u] > Low[v]) Low[u] = Low[v];
            if(Low[v] > DFN[u])
            {
                bridge++;
                Edge[i].cut = true;
                Edge[i^1].cut = true;
            }
            if(u != pre && Low[v] >= DFN[u])
            {
                cut[u] = true;
            }
        }
        else if(Low[u] > DFN[v])
            Low[u] = DFN[v];
    }
    if(u == pre && son > 1) cut[u] = true;
    Instack[u] = false;
    top--;
}


void solve()
{
    int n,m;
    scanf("%d",&n);
    init();
    for(int i = 0; i < n; i++)
    {
        int u,v;
        scanf("%d (%d)",&u,&m);
        u++;
        while(m--)
        {
            scanf("%d",&v);
            v++;
            if(v <= u) continue;
            add(u,v);
            add(v,u);
        }

    }
    Index = top = 0;
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    memset(cut,false,sizeof(cut));
    bridge = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!DFN[i])
            Tarjan(i,i);
    }
    printf("%d critical links\n",bridge);
    vector<pair<int,int> >ans;
    for(int j = 1; j <= n; j++)
    {
        for(int i = head[j]; i != -1; i = Edge[i].next)
        {
            if(Edge[i].cut && Edge[i].to > j)
                ans.push_back(make_pair(j,Edge[i].to));
        }
    }
    sort(ans.begin(),ans.end());
    for(int i = 0; i < (int)ans.size(); i++)
        printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
}


int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",++cnt);
        solve();
    }
    return 0;
}
