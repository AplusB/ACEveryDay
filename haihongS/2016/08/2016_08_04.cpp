#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=2e5+100;

ll num[maxn];

ll minn(ll x,ll y);
int cmp(ll x,ll y);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
			sum+=num[i];
		}
		sort(num,num+n,cmp);
		ll del=100000000000;
		ll pre=0;
		for(int i=0;i<n;i++)
		{
			pre+=num[i];
			del=minn(del,abs(sum-pre-pre));
			//printf("**%lld\n",del);
		}
		printf("%lld\n",del+1);
	}
	return 0;
}

int cmp(ll x,ll y)
{
	return x>y;
}

ll minn(ll x,ll y)
{
	if(x>y) return y;
	return x;
}
