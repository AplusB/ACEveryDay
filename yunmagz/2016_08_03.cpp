//hdu5407 CRB and Candies
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
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL re=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define N 1000010
int divz[N];
int divnum[N];
int pownum[N];
LL lcm[N];

int Pow(int x,int y){
    long long int tempx=x;
    long long int ans=1;

    while(y){
        if(y%2){
            ans=ans*tempx%mod;
        }
        y=y/2;
        tempx=tempx*tempx%mod;
    }

    return (int)ans;
}

int main(){
    for(int i=2;i<N;i++){
        if(divnum[i]==0){
        divz[i]=i;
        divnum[i]=1;
            for(int j=i+i;j<N;j=j+i){
                divnum[j]++;
                divz[j]=i;
            }
        }
    }

    lcm[1]=1;
    for(int i=2;i<N;i++){
        if(divnum[i]==1){
            lcm[i]=lcm[i-1]*divz[i]%mod;
        }
        else{
            lcm[i]=lcm[i-1];
        }
    }

    int t;
    int n;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",lcm[n+1]*Pow(n+1,mod-2)%mod);
    }

    return 0;
}
//hdu5410 CRB and His Birthday
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
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int dp[2020][2],w[2020],a[2020],b[2020];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof dp);
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&w[i],&a[i],&b[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                dp[j][0]=max(dp[j][0],dp[j][1]);
                if(j<w[i]) dp[j][1]=0;
                else dp[j][1]=max(dp[j-w[i]][0]+a[i]+b[i],dp[j-w[i]][1]+a[i]);
            }
        }
        printf("%d\n",max(dp[m][0],dp[m][1]));
    }
    return 0;
}
//hdu5414 CRB and String
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
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL re=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char s1[100010],s2[100010];
bool jg(){
    int l1=strlen(s1);
    int l2=strlen(s2);
    int i,j;
    for(j=1;j<l2;j++) if(s2[j]!=s2[0]) break;
    for(i=0;i<j;i++) if(s1[i]!=s2[i]||i>=l1) return 0;
    while(i<l1){
        while(j<l2){
            if(s1[i]==s2[j]) break;
            j++;
        }
        if(j==l2) return 0;
        i++;
        j++;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s%s",s1,s2);
        if(jg()) puts("Yes");
        else puts("No");
    }
    return 0;
}
//hdu5416 CRB and Tree
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
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL re=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL dp[300010];
int vis[100010];
vector<PII> g[100010];
int mx;
void dfs(int x,int w){
    mx=max(mx,w);
    dp[w]++;
    vis[x]=1;
    int l=SZ(g[x]);
    for(int i=0;i<l;i++){
        if(!vis[g[x][i].fi]){
            dfs(g[x][i].fi,g[x][i].se^w);
        }
    }
}
int main()
{
    int t,n,u,v,w;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) g[i].clear();
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].pb(mp(v,w));
            g[v].pb(mp(u,w));
        }
        memset(vis,0,sizeof vis);
        memset(dp,0,sizeof dp);
        mx=0;
        dfs(1,0);
        int q,s;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&s);
            LL ans=0;
            for(int i=0;i<=mx;i++){
                ans+=dp[i]*dp[i^s];
            }
            if(s==0) ans+=n;
            printf("%lld\n",ans/2);
        }
    }
    return 0;
}
