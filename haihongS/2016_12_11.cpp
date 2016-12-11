#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const double inf=1e9;
const double eps=1e-12;

ll a[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ll ans=-1;
		int rec=-1;
		ll sum=0;
		for(int i=0;i<n;i++)
		{
			if(sum<0) sum=0;
			sum+=a[i];
			if(sum>ans)
			{
				rec=i;
				ans=sum;
			}
		}
		if(ans<0)
		{
			printf("0 %lld %lld\n",a[0],a[n-1]);
			continue;
		}
		printf("%lld",ans);
		ll now=0;
		int lt=rec;
		for(int i=rec;i>=0;i--)
		{
			now+=a[i];
			if(now==ans)
				lt=i;
		}
		printf(" %lld %lld\n",a[lt],a[rec]);
	}
	return 0;
}
