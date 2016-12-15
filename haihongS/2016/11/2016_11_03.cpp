#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+8;


int main()
{
	ll a[3];
	while(~scanf("%lld%lld%lld",&a[0],&a[1],&a[2]))
	{
		ll ans=0;
		sort(a,a+3);
		if(a[1]==0)
		{
			if(a[2]==0 || a[2]==1)
				printf("0\n");
			else if(a[2]==2)
				printf("1\n");
			else
				printf("%lld\n",1+2LL*(a[2]-2));
		}
		else if(a[0]==0)
		{
			if(a[1]==1)
			{
				if(a[2]==1)
					printf("1\n");
				else if(a[2]==2)
					printf("3\n");
				else
					printf("%lld\n",3+3LL*(a[2]-2));					
			}
			else
				printf("%lld\n",6+4LL*(a[1]+a[2]-4));
		}
		else
		{
			if(a[0]>=2)
			{
				ans=15LL+6LL*(a[0]+a[1]+a[2]-6);
				printf("%lld\n",ans);
			}
			else if(a[0]==1)
			{
				if(a[1]==1)
				{
					if(a[2]==1) printf("3\n");
					else if(a[2]==2) printf("6\n");
					else printf("%lld\n",6LL+4LL*(a[2]-2));
				}
				else if(a[1]==2)
				{
					if(a[2]==2) printf("10\n");
					else printf("%lld\n",10LL+5LL*(a[2]-2));
				}
				else
				
					printf("%lld\n",10LL+5LL*(a[0]+a[1]+a[2]-5));
			}
		}
	}
	return 0;
}
