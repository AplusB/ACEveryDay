#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

ll a[maxn],ans[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		ll maxx=0;
		for(int i=n;i>=1;i--)
		{
			if(a[i]>maxx) ans[i]=0;
			else ans[i]=maxx+1-a[i];
			maxx=max(maxx,a[i]);
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=1) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");

	}
	return 0;
}
