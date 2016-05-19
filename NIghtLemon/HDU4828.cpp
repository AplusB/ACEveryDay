#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100007],ans[100007];
const ll MOD = 1000000007;
void init()
{
	a[1] = ans[0] = ans[1] = 1LL;
	for(int i=2 ; i <= 1000001 ; i++)
		a[i] = (MOD - MOD / i) * a[MOD % i] % MOD;
	for(int i=2 ; i <= 100000 ; i++)
		ans[i] = ans[i-1] * (i*4-2) % MOD * a[i+1] % MOD; 
}

int main()
{
	int T,n,NT = 0;
	init();
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("Case #%d:\n%I64d\n",++NT,ans[n]);	
	}
	return 0;
}
