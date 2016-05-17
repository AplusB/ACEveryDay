#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 111

struct Edge{
    int v,next;
}edge[MAXN<<1];
int NE,head[MAXN];
void addEdge(int u,int v){
    edge[NE].v=v; edge[NE].next=head[u];
    head[u]=NE++;
}

int n,k,val[MAXN],d[MAXN][MAXN];
void dp(int u,int fa){
    d[u][0]=0; d[u][1]=val[u];
    for(int i=head[u]; i!=-1; i=edge[i].next){
        int v=edge[i].v;
        if(v==fa) continue;
        dp(v,u);
        for(int a=k; a>=2; --a){
            for(int b=0; b<a; ++b){
                if(d[u][a-b]==-1 || d[v][b]==-1) continue;
                d[u][a]=max(d[u][a],d[u][a-b]+d[v][b]);
            }
        }
    }
}

int main(){
    int a,b;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0; i<n; ++i){
            scanf("%d",val+i);
        }
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=1; i<n; ++i){
            scanf("%d%d",&a,&b);
            addEdge(a,b);
            addEdge(b,a);
        }
        memset(d,-1,sizeof(d));
        dp(0,0);
        int res=-1;
        for(int i=0; i<n; ++i){
            res=max(res,d[i][k]);
        }
        printf("%d\n",res);
    }
    return 0;
}
