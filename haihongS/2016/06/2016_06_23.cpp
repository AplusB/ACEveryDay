#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=2e5+9;
typedef long long ll;


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ll ans=0;
		ll tmp=(ll)n;
		ans=3*tmp*(tmp+3)-6*tmp+1;
		printf("%lld\n",ans);
	}
	return 0;
}

