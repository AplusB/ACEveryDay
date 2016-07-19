//Codeforces Round #361 (Div. 2)
//D - Friends and Subsequences
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
const int MAXN=200005;
int mm[MAXN];
struct ST
{
    int dp[MAXN][20],ty;
    void build(int n,int b[],int _ty)
    {
        ty=_ty;
        for(int i=1;i<=n;i++)
            dp[i][0]=ty*b[i];
        for(int j=1;j<=mm[n];j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
    int query(int x,int y)
    {
        int k=mm[y-x+1];
        return ty*max(dp[x][k],dp[y-(1<<k)+1][k]);
    }
}rmq_a,rmq_b;
int a[MAXN],b[MAXN];
void init(){
    for(int i=-(mm[0]=-1);i<MAXN;i++)
        mm[i]=mm[i-1]+((i&(i-1))==0);
}
int main(){
    init();
    int n;
    cin>>n;
    LL ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    rmq_a.build(n,a,1);
    rmq_b.build(n,b,-1);
    for(int i=1;i<=n;i++){
        int l=i,r=n+1;
        while(l<r){
            int m=(l+r)>>1;
            int mx=rmq_a.query(i,m);
            int mn=rmq_b.query(i,m);
            if(mx>=mn) r=m;
            else l=m+1;
        }
        ans-=l;
        l=i,r=n+1;
        while(l<r){
            int m=(l+r)>>1;
            int mx=rmq_a.query(i,m);
            int mn=rmq_b.query(i,m);
            if(mx>mn) r=m;
            else l=m+1;
        }
        ans+=l;
    }
    cout<<ans<<endl;
    return 0;
}
