#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define INF (1<<30)
#define MAXN 11

struct Edge{
    int v,c,p,r,next;
}edge[MAXN<<1];
int NE,head[MAXN];
void addEdge(int u,int v,int c,int p,int r){
    edge[NE].v=v; edge[NE].c=c; edge[NE].p=p; edge[NE].r=r;
    edge[NE].next=head[u]; head[u]=NE++;
}

struct Node{
    int u,s;
    Node(int _u,int _s):u(_u),s(_s){}
};

int n,d[MAXN][1024];
bool vis[MAXN][1024];
int SPFA(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<(1<<n); ++j){
            d[i][j]=INF; vis[0][1]=0;
        }
    }
    d[0][1]=0; vis[0][1]=1;
    queue<Node> que;
    que.push(Node(0,1));
    while(!que.empty()){
        int u=que.front().u,s=que.front().s; que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            int tmp=d[u][s];
            if(s>>edge[i].c&1){
                tmp+=edge[i].p;
            }else{
                tmp+=edge[i].r;
            }
            if(d[v][s|(1<<v)]>tmp){
                d[v][s|(1<<v)]=tmp;
                if(!vis[v][s|(1<<v)]){
                    vis[v][s|(1<<v)]=1;
                    que.push(Node(v,s|(1<<v)));
                }
            }
        }
        vis[u][s]=0;
    }
    int res=INF;
    for(int i=0; i<(1<<n); ++i){
        res=min(res,d[n-1][i]);
    }
    return res;
}

int main(){
    int m,a,b,c,p,r;
    while(~scanf("%d%d",&n,&m)){
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<m; ++i){
            scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
            --a; --b; --c;
            addEdge(a,b,c,p,r);
        }
        int ans=SPFA();
        if(ans==INF) puts("impossible");
        else printf("%d\n",ans);
    }
    return 0;
}
