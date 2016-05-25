//**tarjan算法，所有树枝边都是桥（dfn[u]<low[v]）,利用vector存储一下就可以了
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn=10010;
const int maxm=100010;
struct node{
    int v,next;
    bool cut;
}edge[maxm];

int head[maxn],ip;

void init(){
    memset(head,-1,sizeof(head));
    ip=0;
}

void addedge(int u,int v){
    edge[ip].v=v,edge[ip].next=head[u],edge[ip].cut=false,head[u]=ip++;
}

int dfn[maxn],low[maxn],index;
int bridge;
int n;

void tarjan(int u,int pre){
    dfn[u]=low[u]=++index;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v == pre)continue;//重边
        if(!dfn[v]){
            tarjan(v,u);
            if(low[u]>low[v])low[u]=low[v];
            ///桥
            if(low[v]>dfn[u]){
                bridge++;
                edge[i].cut=true;
                edge[i^1].cut=true;
            }
        }
        else if(low[u]>dfn[v])
            low[u]=dfn[v];
    }
}

void solve(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    index=0,bridge=0;
    for(int i = 1; i <= n; ++i){
        if(!dfn[i])
            tarjan(i,i);
    }
    
    printf("%d critical links\n",bridge);
    
    vector<pair<int,int> >ans;
    for(int u=1;u<=n;u++)
        for(int i=head[u];i!=-1;i=edge[i].next)
            if(edge[i].cut && edge[i].v > u)
                ans.push_back(make_pair(u,edge[i].v));
                
    sort(ans.begin(),ans.end());
    
    for(int i=0;i<ans.size();i++)
        printf("%d - %d\n",ans[i].first-1,ans[i].second-1);
    puts("");
}

int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    while(~scanf("%d",&n)){
        init();
        for(int i = 0; i < n; ++i){
            int u,num;
            scanf("%d (%d)",&u,&num);
            u++;
            while(num--){
                int v;
                scanf("%d",&v);
                v++;
                if(v<=u)
                    continue;
                addedge(u,v);
                addedge(v,u);
            }
        }
        solve();
    }
    return 0;
}
