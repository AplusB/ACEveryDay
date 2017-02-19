#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 2e9 + 9;

int a[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if(n==0)
		{
			printf("1\n");continue;
		}
		int pos=0,now=8;
		a[pos++]=now;
		now*=8;
		now%=10;
		while(now!=8)
		{
			a[pos++]=now;
			now*=8;
			now%=10;
		}
		n%=4;
		if(n==0) printf("%d\n",a[pos-1]);
		else printf("%d\n",a[n-1]);

	}
	return 0;
}
