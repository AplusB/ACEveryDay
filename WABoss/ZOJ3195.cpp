#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 55555

struct Edge{
    int v,w,next;
}edge[MAXN<<1];
int NE,head[MAXN];
void addEdge(int u,int v,int w){
    edge[NE].v=v; edge[NE].w=w; edge[NE].next=head[u];
    head[u]=NE++;
}

int dep[MAXN],weight[MAXN],par[17][MAXN];
void dfs(int u,int fa,int w){
    weight[u]=w;
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        par[0][v]=u;
        dfs(v,u,w+edge[i].w);
    }
}

void init(int n){
    dfs(0,0,0);
    for(int i=1; i<17; ++i){
        for(int j=0; j<n; ++j){
            if(par[i-1][j]==-1) continue;
            par[i][j]=par[i-1][par[i-1][j]];
        }
    }
}

int lca(int u,int v){
    if(dep[u]>dep[v]) swap(u,v);
    for(int k=0; k<17; ++k){
        if(dep[v]-dep[u]>>k&1){
            v=par[k][v];
        }
    }
    if(v==u) return u;
    for(int k=16; k>=0; --k){
        if(par[k][u]!=par[k][v]){
            u=par[k][u];
            v=par[k][v];
        }
    }
    return par[0][u];
}

int calc(int u,int v){
    return weight[u]+weight[v]-2*weight[lca(u,v)];
}

int main(){
    int n,q,a,b,c;
    bool flag=0;
    while(~scanf("%d",&n)){
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=1; i<n; ++i){
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }

        memset(par,-1,sizeof(par));
        init(n);

        if(flag) putchar('\n');
        else flag=1;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&a,&b,&c);
            printf("%d\n",calc(a,b)+calc(b,c)+calc(a,c)>>1);
        }
    }
    return 0;
}
