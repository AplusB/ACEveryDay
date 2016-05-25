#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN 5555
#define MAXM 1111111
struct Edge{
    int v,next;
}edge[MAXM<<1];
int NE,head[MAXN];
void addEdge(int u,int v){
    edge[NE].v=v; edge[NE].next=head[u];
    head[u]=NE++;
}
struct Node{
    int u,t;
    Node(int _u=0,int _t=0):u(_u),t(_t){}
};
int n,k;
int d[MAXN][55],mindist[MAXN];
long long cnt[MAXN][55];
bool flag[MAXN];
bool BFS(){
    if(k==0 && flag[1]) return 0;
    memset(d,127,sizeof(d));
    memset(mindist,127,sizeof(mindist));
    memset(cnt,0,sizeof(cnt));
    d[1][flag[1]]=0;
    mindist[1]=0;
    cnt[1][flag[1]]=1;
    queue<Node> que;
    que.push(Node(1,flag[1]));
    while(!que.empty()){
        int u=que.front().u,t=que.front().t; que.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next){
            int v=edge[i].v;
            if(t+flag[v]>k || mindist[v]<d[u][t]+1) continue;

            if(mindist[v]==d[u][t]+1){
                cnt[v][t+flag[v]]+=cnt[u][t];
            }else{
                d[v][t+flag[v]]=d[u][t]+1;
                cnt[v][t+flag[v]]=cnt[u][t];
                mindist[v]=d[u][t]+1;
            }
            que.push(Node(v,t+flag[v]));
        }
    }
    return mindist[n]<111111111;
}
int main(){
    int m,a,b;
    while(~scanf("%d%d%d",&m,&n,&k)){
        NE=0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<n; ++i){
            scanf("%d%d",&a,&b);
            flag[a]=b;
        }
        for(int i=0; i<m; ++i){
            scanf("%d%d",&a,&b);
            addEdge(a,b);
            addEdge(b,a);
        }
        if(!BFS()){
            puts("Impossible!");
            continue;
        }
        long long res=0;
        for(int i=0; i<=k; ++i) res+=cnt[n][i];
        printf("%lld\n",res);
    }
    return 0;
}
