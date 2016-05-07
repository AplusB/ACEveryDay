#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 111111

struct Edge{
    int v,w,next;
}edge[MAXN<<1];
int NE,head[MAXN];
void addEdge(int u,int v,int w){
    edge[NE].v=v; edge[NE].w=w; edge[NE].next=head[u];
    head[u]=NE++;
}

int dep[MAXN],par[17][MAXN],upp[17][MAXN];
void dfs(int u,int fa){
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dep[v]=dep[u]+1;
        par[0][v]=u;
        upp[0][v]=edge[i].w;
        dfs(v,u);
    }
}

void init(int n){
    for(int i=1; i<17; ++i){
        for(int j=1; j<=n; ++j){
            if(par[i-1][j]==0){
                par[i][j]=0;
                continue;
            }
            par[i][j]=par[i-1][par[i-1][j]];
            if(upp[i-1][j]==1 && upp[i-1][par[i-1][j]]==1){
                upp[i][j]=1;
            }else if(upp[i-1][j]==-1 && upp[i-1][par[i-1][j]]==-1){
                upp[i][j]=-1;
            }else{
                upp[i][j]=0;
            }
        }
    }
}
bool lca(int u,int v){
    if(dep[u]>dep[v]){
        for(int i=0; i<17; ++i){
            if((dep[u]-dep[v])>>i&1){
                if(upp[i][u]!=1) return 0;
                u=par[i][u];
            }
        }
        if(u==v) return 1;
        for(int i=16; i>=0; --i){
            if(par[i][u]!=par[i][v]){
                if(upp[i][u]!=1 || upp[i][v]!=-1) return 0;
                u=par[i][u]; v=par[i][v];
            }
        }
        if(upp[0][u]!=1 || upp[0][v]!=-1) return 0;
    }else{
        for(int i=0; i<17; ++i){
            if((dep[v]-dep[u])>>i&1){
                if(upp[i][v]!=-1) return 0;
                v=par[i][v];
            }
        }
        if(u==v) return 1;
        for(int i=16; i>=0; --i){
            if(par[i][u]!=par[i][v]){
                if(upp[i][u]!=1 || upp[i][v]!=-1) return 0;
                u=par[i][u]; v=par[i][v];
            }
        }
        if(upp[0][u]!=1 || upp[0][v]!=-1) return 0;
    }
    return 1;
}

int main(){
    int n,q,a,b;
    while(~scanf("%d",&n)){
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=1; i<n; ++i){
            scanf("%d%d",&a,&b);
            addEdge(a,b,-1);
            addEdge(b,a,1);
        }

        dfs(1,1);
        init(n);

        scanf("%d",&q);
        while(q--){
            scanf("%d%d",&a,&b);
            if(lca(a,b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
