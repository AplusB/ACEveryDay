#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+9;
const int inf=2e9+9;
typedef long long ll;

int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		if(n%2==0)
			printf("%lld\n",n/2);
		else
			printf("%lld\n",-1LL*(n+1)/2);
	}
	return 0;
}
