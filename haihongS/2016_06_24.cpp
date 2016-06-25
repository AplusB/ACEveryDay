#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		if(n&1)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}
