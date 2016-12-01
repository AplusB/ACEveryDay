#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=500+60;
const int inf=2e9+9;

int judge(ll x);

int main()
{
	ll v;
	scanf("%lld",&v);
	for(ll i=1;;i++)
	{
		if(judge(v+i))
		{
			printf("%lld\n",i);
			break;

		}
	}
	return 0;
}

int judge(ll x)
{
	if(x<0) x=-x;
	while(x)
	{
		if(x%10==8) return 1;
		x/=10;
	}
	return 0;
}
