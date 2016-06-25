#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ll ans=0;
		ll di=2;
		for(int i=1;i<=n;i++)
		{
			ans+=di;
			di*=2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
