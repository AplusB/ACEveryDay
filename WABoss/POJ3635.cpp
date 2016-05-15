#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1<<30)
#define MAXN 1111
#define MAXM 111111

struct Edge{
    int v,w,next;
}edge[MAXM<<1];
int NE,head[MAXN];
void addEdge(int u,int v,int w){
    edge[NE].v=v; edge[NE].w=w; edge[NE].next=head[u];
    head[u]=NE++;
}

int vs,vt,cap;
int price[MAXN],d[MAXN][111];
bool vis[MAXN][111];

struct Node{
    int u,w,d;
    Node(int _u=0,int _w=0,int _d=0):u(_u),w(_w),d(_d){}
    bool operator<(const Node &nd)const{
        return nd.d<d;
    }
};

int dijkstra(){
    memset(d,127,sizeof(d));
    memset(vis,0,sizeof(vis));
    priority_queue<Node> que;
    for(int i=0; i<=cap; ++i){
        d[vs][i]=price[vs]*i;
        que.push(Node(vs,i,d[vs][i]));
    }

    while(!que.empty()){
        Node nd=que.top(); que.pop();
        if(nd.u==vt) return nd.d;
        if(vis[nd.u][nd.w]) continue;
        vis[nd.u][nd.w]=1;

        if(nd.w<cap && d[nd.u][nd.w+1]>d[nd.u][nd.w]+price[nd.u]){
            d[nd.u][nd.w+1]=d[nd.u][nd.w]+price[nd.u];
            que.push(Node(nd.u,nd.w+1,d[nd.u][nd.w+1]));
        }

        for(int i=head[nd.u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            if(edge[i].w>nd.w) continue;
            int nw=nd.w-edge[i].w;
            if(d[v][nw]>d[nd.u][nd.w]){
                d[v][nw]=d[nd.u][nd.w];
                que.push(Node(v,nw,d[v][nw]));
            }
        }
    }
    return INF;
}

int main(){
    int n,m,q,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; ++i){
        scanf("%d",price+i);
    }
    memset(head,-1,sizeof(head));
    while(m--){
        scanf("%d%d%d",&a,&b,&c);
        addEdge(a,b,c);
        addEdge(b,a,c);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&cap,&vs,&vt);
        int res=dijkstra();
        if(res==INF) puts("impossible");
        else printf("%d\n",res);
    }
    return 0;
}
