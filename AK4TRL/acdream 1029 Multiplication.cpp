//求前缀和
//虽然是水题，但提交时各种爆longlong，最后全部mod上后交还是错，后来发现格式是最后一个数直接输出没有空格
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
ll a[100005], b[100005];
ll asum[100005], bsum[100005];
ll sum[100005];
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n;
	scanf("%d",&n);
	memset(asum,0,sizeof asum);
	memset(bsum,0,sizeof bsum);
	memset(sum,0,sizeof sum);
	for(int i = 1; i <= n; ++i){
		scanf("%lld",&a[i]);
		asum[i] = (asum[i-1] + a[i]) % mod;
	}

	for(int i = 1; i <= n; ++i){
		scanf("%lld",&b[i]);
		bsum[i] = (bsum[i-1] + b[i]) % mod;
	}

	ll ans = 0;
	for(int i = 1; i <= n; ++i)
		sum[i] = ((a[i]*b[i]%mod + a[i]*bsum[i-1]%mod + b[i]*asum[i-1]%mod))%mod;

	for(int i = 1; i < n; ++i)
		printf("%lld ",sum[i]);
	printf("%lld\n",sum[n]);

	return 0;
}
