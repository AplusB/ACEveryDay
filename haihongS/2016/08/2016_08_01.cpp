#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>

typedef long long ll;
const int maxn=5e5+9;

ll num[maxn];

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
			sum+=num[i];
		}
		ll lt,rt,mid,ans1;
		lt=0,rt=1e9+9,ans1=0;
		while(lt<=rt)
		{
			mid=lt+(rt-lt)/2;
			ll tmp=0;
			for(int i=0;i<n;i++)
			{
				if(num[i]<mid)
					tmp+=mid-num[i];
			}
			if(tmp<=k)
			{
				ans1=mid;lt=mid+1;
			}
			else
				rt=mid-1;
		}
		lt=0,rt=1e9+9;
		ll ans2=rt;
		while(lt<=rt)
		{
			mid=lt+(rt-lt)/2;
			ll tmp=0;
			for(int i=0;i<n;i++)
			{
				if(num[i]>mid)
					tmp+=num[i]-mid;
			}
			if(tmp<=k)
			{
				ans2=mid;rt=mid-1;
			}
			else
				lt=mid+1;
		}
		if(ans1<ans2)
			printf("%lld\n",ans2-ans1);
		else
		{
			if(sum%n==0)
				printf("0\n");
			else
				printf("1\n");
		}
	}
    return 0;
}
