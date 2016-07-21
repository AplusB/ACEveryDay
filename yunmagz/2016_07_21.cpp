//hdu5299Circles Game
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
const LL mod=1e9+7;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
VI g[20010];
struct node {
    int x,y,r,v;
    bool operator < (const node &A) const
    {
        return r>A.r;
    }
}a[20010];
bool cal(int k,int n){
    LL dis=(a[k].x-a[n].x)*(a[k].x-a[n].x)+(a[k].y-a[n].y)*(a[k].y-a[n].y);
    if(dis<=a[k].r*a[k].r) return 1;
    return 0;
}
void dfs(int fa,int x){
    for(int i=0;i<g[fa].size();i++){
        if(cal(g[fa][i],x)){
            dfs(g[fa][i],x);
            return;
        }
    }
    g[fa].pb(x);
}
int solve(int x){
    int ans=0;
    for(int i=0;i<SZ(g[x]);i++){
        ans^=1+solve(g[x][i]);
    }
    return ans;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        a[0].x=0;
        a[0].y=0;
        a[0].r=100000;
        a[0].v=0;
        g[0].clear();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
            a[i].v=0;
            g[i].clear();
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
            dfs(0,i);
        if(solve(0)) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
