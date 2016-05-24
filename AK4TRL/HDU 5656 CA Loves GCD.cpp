//01背包+GCD
//dp[i][j]表示前i个数中任意组合，各组合的GCD为j的个数
//当dp[i][j]有个数时，可以看看当再增加一个数时的情况，即dp[i+1][gcd(a[i],j)]
//取数组最大值，因GCD(a,b)<=数组最大值
//若不取a[i],则为dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod直接计算，否则dp[i+1][gcd(a[i],j)] = (dp[i+1][gcd(a[i],j)] + dp[i][j]) % mod
// i 可理解为取 i 个， 再取一个为 i + 1
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod = 100000007;
int a[1005], dp[1005][1005];
int gcd(int a, int b){
	return !b ? a : gcd(b,a%b);
}
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int t;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof a);
		int n;
		scanf("%d",&n);
		int maxn = 0;
		for(int i = 0; i < n; ++i)
			scanf("%d",&a[i]), maxn = max(a[i], maxn);

		memset(dp,0,sizeof dp);
		for(int i = 0; i < n; ++i){
			dp[i+1][a[i]] = 1;
			for(int j = maxn; j >= 1; j--){
				dp[i+1][j] = (dp[i+1][j]+dp[i][j])%mod;
				if(dp[i][j]){
					dp[i+1][gcd(a[i],j)] = (dp[i+1][gcd(a[i],j)] + dp[i][j]) % mod;
				}
			}
		}

		//for(int i = 1; i <= n; ++i){
		//	for(int j = 1; j <= maxn; ++j)
		//		cout << dp[i][j] << ' ' ;
		//	puts("");
		//}
		//puts("");

		ll ans = 0;
		for(int i = 1;i <= maxn; ++i)
			ans = (ans + (ll)i * dp[n][i]) % mod;
		printf("%lld\n",ans);

	}

	return 0;
}
