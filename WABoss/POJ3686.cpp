#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1<<30)
#define MAXN 2555
#define MAXM 2555*5555

struct Edge{
    int u,v,cap,cost,next;
}edge[MAXM];
int head[MAXN];
int NV,NE,vs,vt;

void addEdge(int u,int v,int cap,int cost){
    edge[NE].u=u; edge[NE].v=v; edge[NE].cap=cap; edge[NE].cost=cost;
    edge[NE].next=head[u]; head[u]=NE++;
    edge[NE].u=v; edge[NE].v=u; edge[NE].cap=0; edge[NE].cost=-cost;
    edge[NE].next=head[v]; head[v]=NE++;
}
bool vis[MAXN];
int d[MAXN],pre[MAXN];
bool SPFA(){
    for(int i=0;i<NV;++i){
        vis[i]=0; d[i]=INF;
    }
    vis[vs]=1; d[vs]=0;
    queue<int> que;
    que.push(vs);
    while(!que.empty()){
        int u=que.front(); que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].cap && d[v]>d[u]+edge[i].cost){
                d[v]=d[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
        vis[u]=0;
    }
    return d[vt]!=INF;
}
int MCMF(){
    int res=0;
    while(SPFA()){
        int flow=INF,cost=0;
        for(int u=vt; u!=vs; u=edge[pre[u]].u){
            flow=min(flow,edge[pre[u]].cap);
        }
        for(int u=vt; u!=vs; u=edge[pre[u]].u){
            edge[pre[u]].cap-=flow;
            edge[pre[u]^1].cap+=flow;
            cost+=flow*edge[pre[u]].cost;
        }
        res+=cost;
    }
    return res;
}

int main(){
    int t,n,m,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        vs=n*m+n; vt=vs+1; NV=vt+1; NE=0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<n; ++i){
            addEdge(vs,i,1,0);
            for(int j=0; j<m; ++j){
                scanf("%d",&a);
                for(int k=0; k<n; ++k){
                    addEdge(i,j+k*m+n,1,(k+1)*a);
                }
            }
        }
        for(int j=0; j<m; ++j){
            for(int k=0; k<n; ++k){
                addEdge(j+k*m+n,vt,1,0);
            }
        }
        printf("%.6f\n",MCMF()*1.0/n);
    }
    return 0;
}
