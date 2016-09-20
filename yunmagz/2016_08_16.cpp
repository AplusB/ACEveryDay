//2016 Multi-University Training Contest 9
//1012	Less Time, More profit
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAXN = 450;//点数的最大值
const int MAXM = 1010*1010*2;//边数的最大值
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow;
}edge[MAXM];//注意是MAXM
int tol;
int head[MAXN];
int gap[MAXN],dep[MAXN],cur[MAXN];
void init()
{
    tol = 0;
    memset(head,-1,sizeof (head));
}
void addedge (int u,int v,int w,int rw = 0)
{
    edge[tol].to = v; edge[tol].cap = w; edge[tol].flow = 0;
    edge[tol].next = head[u]; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].flow = 0;
    edge[tol].next = head[v]; head[v] = tol++;
}
int Q[MAXN];
void BFS(int start,int end)
{
    memset(dep,-1,sizeof(dep));
    memset(gap,0,sizeof(gap));
    gap[0] = 1;
    int front = 0, rear = 0;
    dep[end] = 0;
    Q[rear++] = end;
    while(front != rear)
    {
        int u = Q[front++];
        for(int i = head[u]; i !=  -1; i = edge[i].next)
        {
            int v = edge[i]. to;
            if(dep[v] != -1)continue;
            Q[rear++] = v;
            dep[v] = dep[u] + 1;
            gap[dep[v]]++;
        }
    }
}
int S[MAXN];
int sap(int start,int end, int N)
{
    BFS(start,end);
    memcpy(cur,head,sizeof(head));
    int top = 0;
    int u = start;
    int ans = 0;
    int i;
    while(dep[start] < N)
    {
        if(u == end)
        {
            int Min = INF;
            int inser;
            for( i = 0;i < top;i++)
            {
                if(Min > edge[S[i]].cap - edge[S[i]].flow)
                {
                    Min = edge[S[i]].cap - edge[S[i]].flow;
                    inser = i;
                }
            }
            for( i = 0;i < top;i++)
            {
                edge[S[i]]. flow += Min;
                edge[S[i]^1].flow -= Min;
            }
            ans += Min;
            top = inser;
            u = edge[S[top]^1].to;
            continue;
        }
        bool flag =  false;
        int v;
        for( i = cur[u]; i != -1; i = edge[i]. next)
        {
            v = edge[i]. to;
            if(edge[i].cap - edge[i].flow && dep[v]+1 == dep[u])
            {
                flag =  true;
                cur[u] = i;
                break;
            }
        }
        if(flag)
        {
            S[top++] = cur[u];
            u = v;
            continue;
        }
        int Min = N;
        for( i = head[u]; i !=  -1; i = edge[i].next)
        {
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
            {
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != start)u = edge[S[--top]^1].to;
    }
    return ans;
}

struct node {
    int pay,t;
}p[220];
int pro[220];
int k[220];
int x[220][220];
int main()
{
    int tt,n,cas=1,m,L;
    scanf("%d",&tt);
    while(tt--){
//        memset(pre,-1,sizeof(pre));
        scanf("%d%d%d",&n,&m,&L);
        int s=0,t=n+m+1;
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].pay,&p[i].t);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&pro[i],&k[i]);
            for(int j=1;j<=k[i];j++){
                scanf("%d",&x[i][j]);
            }
        }
        int l=0,r=1e9+1;
        int mnt=-1,mxp=0;
        while(l<=r){
            int mid=(l+r)>>1;
            init();
            for(int i=1;i<=n;i++)
                if(p[i].t<=mid) addedge(i,t,p[i].pay);
                else addedge(i,t,inf);
            int sum=0;
            for(int i=1;i<=m;i++){
                sum+=pro[i];
                addedge(s,n+i,pro[i]);
                for(int j=1;j<=k[i];j++)
                    addedge(n+i,x[i][j],inf);
            }
            int ans=sap(s,t,n+m+2);
            if(sum-ans<L) l=mid+1;
            else {
                r=mid-1;
                mnt=mid;
                mxp=sum-ans;
            }
        }
        printf("Case #%d: ",cas++);
        if(mnt==-1) puts("impossible");
        else printf("%d %d\n",mnt,mxp);
//        printf("%d\n",sum - dinic(s,t));
    }
    return 0;
}
