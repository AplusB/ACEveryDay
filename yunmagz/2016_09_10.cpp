//2016 ACM/ICPC Asia Regional Dalian Online
//1002	Different GCD Subarray Query
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
typedef long long LL;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=1e5+5;

int n,m;
int dp[maxn][20];

struct ow
{
    int l,r,id;
    bool operator<(const ow &rhs)const
    {
        return r<rhs.r;
    }
} p[maxn*10];

struct TT
{
    int l,r,v;
    bool operator<(const TT &rhs)const
    {
        return r<rhs.r;
    }
} seg[maxn*35];
int erfen(int pos,int v)
{
    int l=1,r=pos;
    while(l<r)
    {
        int mid=(l+r)>>1;
        int len=pos-mid+1;
        int now=pos,cur=-1;
        for(int i=16; i>=0; --i)
        {
            if(len&(1<<i))
            {
                if(cur==-1)cur=dp[now][i];
                else cur=__gcd(cur,dp[now][i]);
                now-=(1<<i);
            }
        }
        if(cur<v)l=mid+1;
        else r=mid;
    }
    return (l+r)>>1;
}
int has[35*maxn],tot,mat[35*maxn];
int res[maxn*10];
int c[maxn];
void add(int x,int t)
{
    for(int i=x; i<=n; i+=i&(-i))
        c[i]+=t;
}
int get(int x)
{
    int ans=0;
    if(x==0)return 0;
    for(int i=x; i>0; i-=i&(-i))
        ans+=c[i];
    return ans;
}
void init()
{
    for(int i=1; i<=n; ++i)
        scanf("%d",&dp[i][0]);
    for(int i=1; i<=m; ++i)
        scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i;
    for(int k=1; (1<<k)<=n; ++k)
        for(int i=n; i>1; --i)
        {
            int j=i-(1<<k)+1;
            if(j<1)break;
            j=i-(1<<(k-1));
            dp[i][k]=__gcd(dp[i][k-1],dp[j][k-1]);
        }
}
void gao()
{
    int cnt=0;
    tot=0;
    for(int i=1; i<=n; ++i)
    {
        int last=-1;
        for(int j=i; j>0; --j)
        {
            int tmp=dp[j][0];
            if(last!=-1)tmp=__gcd(tmp,last);
            last=tmp;
            ++cnt;
            seg[cnt].l=j,seg[cnt].r=i,seg[cnt].v=last;
            has[++tot]=last;
            j=erfen(i,last);
        }
    }
    sort(has+1,has+1+tot);
    tot=unique(has+1,has+1+tot)-has-1;
    sort(p+1,p+1+m);
    sort(seg+1,seg+1+cnt);
    memset(mat,0,sizeof(mat));
    memset(c,0,sizeof(c));
    int now=1;
    for(int i=1; i<=m; ++i)
    {
        for(; now<=cnt&&seg[now].r<=p[i].r; ++now)
        {
            int pos=lower_bound(has+1,has+1+tot,seg[now].v)-has;
            if(seg[now].l>mat[pos])
            {
                if(mat[pos])add(mat[pos],-1);
                add(seg[now].l,1);
                mat[pos]=seg[now].l;
            }
        }
        res[p[i].id]=get(p[i].r)-get(p[i].l-1);
    }
    for(int i=1; i<=m; ++i)
        printf("%d\n",res[i]);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        gao();
    }
    return 0;
}
//1006	Football Games
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

int a[20010];
int main()
{
    int t,n,m;
    while(~scanf("%d",&t)){
        while(t--){
            scanf("%d",&n);
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
            }
            sort(a+1,a+n+1);
            LL sum=0;
            int f=1;
            for(int i=1;i<=n&&f;i++){
                sum+=a[i];
                if(sum<i*(i-1)) f=0;
            }
            if(sum!=n*(n-1)) f=0;
            if(f) puts("T");
            else puts("F");
        }
    }
    return 0;
}
//1007	Friends and Enemies
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

int main()
{
    LL n,m;
    while(~scanf("%I64d%I64d",&n,&m)){
        if(n*n/4<=m) puts("T");
        else puts("F");
    }
    return 0;
}
