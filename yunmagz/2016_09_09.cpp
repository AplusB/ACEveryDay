//hdu3715 Go Deeper
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
const LL mod=1e9+7;
const LL INF=1e18;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAXN = 410;
const int MAXM = 40010;
struct Edge
{
    int to,next;
} edge[MAXM];
int head[MAXN],tot;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
bool vis[MAXN];//染色标记，为true表示选择
int S[MAXN],top;//栈
bool dfs(int u)
{
    if(vis[u^1])return false;
    if(vis[u])return true;
    vis[u] = true;
    S[top++] = u;
    for(int i = head[u]; i != -1; i = edge[i].next)
        if(!dfs(edge[i].to))
            return false;
    return true;
}
bool Twosat(int n)
{
    memset(vis,false,sizeof(vis));
    for(int i = 0; i < n; i += 2)
    {
        if(vis[i] || vis[i^1])continue;
        top = 0;
        if(!dfs(i))
        {
            while(top)vis[S[--top]] = false;
            if(!dfs(i^1)) return false;
        }
    }
    return true;
}
int a[10010],b[10010],c[10010];

int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int l=1,r=m,mid;
        while(l<=r){
            mid=(l+r)>>1;
            init();
            for(int i=0;i<mid;i++){
                if(c[i]==0){
                    addedge(a[i]*2,b[i]*2+1);
                    addedge(b[i]*2,a[i]*2+1);
                }
                else if(c[i]==1){
                    addedge(a[i]*2,b[i]*2);
                    addedge(b[i]*2,a[i]*2);
                    addedge(a[i]*2+1,b[i]*2+1);
                    addedge(b[i]*2+1,a[i]*2+1);
                }
                else {
                    addedge(a[i]*2+1,b[i]*2);
                    addedge(b[i]*2+1,a[i]*2);
                }
            }
            if(Twosat(n*2)) l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",l-1);
    }
    return 0;
}
