#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1LL<<60)
#define MAXN 55555
#define MAXM 55555*2

struct Edge{
    int v,w,next;
}edge[MAXM];
int NE,head[MAXN];
void addEdge(int u,int v,int w){
    edge[NE].v=v; edge[NE].w=w; edge[NE].next=head[u];
    head[u]=NE++;
}

long long d[MAXN];
bool vis[MAXN];
bool SPFA(int n){
    for(int i=1; i<=n; ++i){
        d[i]=INF; vis[i]=0;
    }
    d[1]=0; vis[1]=1;
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int u=que.front(); que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            if(d[v]>d[u]+edge[i].w){
                d[v]=d[u]+edge[i].w;
                if(!vis[v]){
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
        vis[u]=0;
    }
    for(int i=1; i<=n; ++i){
        if(d[i]==INF) return 0;
    }
    return 1;
}

int weight[MAXN];
int main(){
    int t,n,m,a,b,c;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; ++i){
            scanf("%d",weight+i);
        }
        NE=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        if(!SPFA(n)){
            puts("No Answer");
            continue;
        }
        long long ans=0;
        for(int i=1; i<=n; ++i){
            ans+=d[i]*weight[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
