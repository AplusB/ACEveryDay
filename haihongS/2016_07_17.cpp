#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const int inf=2e9+9;

ll p[maxn];

int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		int loca=0;
		ll num=n;
		for(ll i=2;i*i<=num;i++)
		{
			if(num%i==0)
			{
				p[loca++]=i;
			}
			while(num%i==0)
			{
				num/=i;
			}
		}
		p[loca++]=num;
		ll ans=1;
		for(int i=0;i<loca;i++)
			ans*=p[i];
		printf("%lld\n",ans);
	}
	return 0;
}
