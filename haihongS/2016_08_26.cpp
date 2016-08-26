#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=2e9+9;

int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		if(n&1)
		{
			ll k,m;
			k=1+n*n;
			k/=2;
			m=n*n-1;
			m/=2;
			if(m>0 && k>0)
				printf("%lld %lld\n",m,k);
			else
				printf("-1\n");
		}
		else
		{
			ll k=4+n*n;
			k/=4;
			ll m=n*n-4;
			m/=4;
			if(k>0 && m>0)
				printf("%lld %lld\n",m,k);
			else
				printf("-1\n");
		}
			
	}
	return 0;
}
