//Codeforces Round #369 (Div. 2)
//D - Directed Roads
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
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int a[200010];
int vis[200010];
LL cnt;
LL ans;
int deps[200010];

void dfs(int u,int dep,int fa)
{
    vis[u] = fa;
    deps[u] = dep;
    if(!vis[a[u]]) dfs(a[u],dep+1,fa);
    else{
        if(vis[a[u]] == vis[u]){
            ans = ans*(powmod(2,deps[u]-deps[a[u]]+1)-2)%mod;
            cnt += deps[u]-deps[a[u]]+1;
        }
    }
}

int main(void)
{
    int n;
    ans = 1;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i++)
        if(!vis[i]) dfs(i,1,i);
    ans = ans*(powmod(2,n-cnt))%mod;
    printf("%I64d",ans);
    return 0;
}
