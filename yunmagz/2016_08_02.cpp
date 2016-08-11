//2016 Multi-University Training Contest 5
//1003 Divide the Sequence
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
LL a[1000010];
int main()
{
    int t,n,m;
    while(~scanf("%d",&n)){
        int ans=0;
        LL sum=0;
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        for(int i=n-1;i>=0;i--){
            sum+=a[i];
            if(sum>=0){
                sum=0;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//1011 Two
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
int a[1010],b[1010];
LL dp[1010][1010];
int main()
{
    int t,n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++) scanf("%d",&b[i]);
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i]==b[j]) dp[i][j]=1+dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
                dp[i][j]=(dp[i][j]%mod+mod)%mod;
            }
        }
        printf("%lld\n",dp[n][m]);
    }
    return 0;
}
//1012 World is Exploding
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
const int INF=0x3f3f3f3f;
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
struct node
{
    int val;
    int id;
} f[50000+10];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
int a[50000+10];
int d[50000+10];
int tree[50010<<2];

inline void push(int rt)
{
    tree[rt] = tree[rt<<1] + tree[rt<<1|1];
}

void build(int l, int r, int rt)
{
    if(l == r)
    {
        tree[rt]=0;
        return ;
    }
    int m = ( l + r )>>1;
    build(lson);
    build(rson);
    push(rt);
}

void updata(int p, int add, int l, int r, int rt)
{
    if( l == r )
    {
        tree[rt] += add;
        return ;
    }
    int m = ( l + r ) >> 1;
    if(p <= m)
        updata(p, add, lson);
    else
        updata(p, add, rson);

    push(rt);
}

int query(int L,int R,int l,int r,int rt)
{
    if( L <= l && r <= R )
    {
        return tree[rt];
    }
    int m = ( l + r ) >> 1;
    int ans=0;
    if(L<=m)
        ans+=query(L,R,lson);
    if(R>m)
        ans+=query(L,R,rson);

    return ans;
}
LL mxl[50000+10],mnl[50000+10],mxr[50000+10],mnr[50000+10];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&f[i].val);
            f[i].id=i;
        }
        sort(f+1,f+1+n,cmp);
        f[0].val=-1;
        int cnt=0;
        for(int i=1; i<=n; i++)
            if(f[i].val==f[i-1].val) d[f[i].id]=cnt;
            else d[f[i].id]=++cnt;
        build(0,n,1);
        LL mx=0,mn=0;
        for(int i=1; i<=n; i++)
        {
            mnl[i]=query(0,d[i]-1,0,n,1);
            mxl[i]=query(d[i]+1,cnt,0,n,1);
            updata(d[i],1,0,n,1);
            mx+=mxl[i];
            mn+=mnl[i];
        }
        build(0,n,1);
        for(int i=n; i>=1; i--)
        {
            mnr[i]=query(0,d[i]-1,0,n,1);
            mxr[i]=query(d[i]+1,cnt,0,n,1);
            updata(d[i],1,0,n,1);
        }
        LL ans=mx*mn;
        for(int i=1;i<=n;i++){
            ans-=mxl[i]*mxr[i]+mnl[i]*mnr[i]+mnl[i]*mxl[i]+mnr[i]*mxr[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
