#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

int main()
{
	ll a,b,c;
	while(~scanf("%lld %lld %lld",&a,&b,&c))
	{
		if(c==0)
		{
			if(a==b) puts("YES");
			else puts("NO");
			continue;
		}
		if(b+c-a==0) 
		{
			puts("NO");
			continue;
		}
		if((b+c-a)%c==0 && (b+c-a)/c>0) puts("YES");
		else puts("NO");
	}
	return 0;
}
