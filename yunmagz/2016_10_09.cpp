//Intel Code Challenge Final Round (Div. 1 + Div. 2, Combined)
//E - Goods transportation
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e4+7;
const double eps=1e-8;
const LL inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

LL dp[2][10010];
int n,c,p[10010],q[10010];
int main() {
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;i++) scanf("%d",&p[i]);
	for(int i=0;i<n;i++) scanf("%d",&q[i]);
	int now=0;
    memset(dp[now],0x20,sizeof dp[now]);
	dp[0][0]=0;
	for(int i=0;i<n;i++) {
        now^=1;
        memset(dp[now],0x20,sizeof dp[now]);
		for(int j=0;j<=i;j++) {
			dp[now][j]=min(dp[now][j],dp[now^1][j]+p[i]+(LL)j*c);
			dp[now][j+1]=min(dp[now][j+1],dp[now^1][j]+q[i]);
		}
	}
	LL ans=1LL<<60;
	for(int i=0;i<=n;i++) ans=min(ans,dp[now][i]);
	printf("%lld\n",ans);
	return 0;
}
