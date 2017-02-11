#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int main()
{
	ll n,a,b,c;
	while(~scanf("%lld%lld%lld%lld",&n,&a,&b,&c))
	{
		if(n%4==0) puts("0");
		else if(n%4==1)
		{
			ll t1=3LL*a,t2=a+b,t3=c;
			ll ans=min(t1,t2);
			ans=min(ans,t3);
			printf("%lld\n",ans);
		}
		else if(n%4==2)
		{
			ll t1=2LL*a,t2=b,t3=2LL*c;
			ll ans=min(t1,t2);
			ans=min(ans,t3);
			printf("%lld\n",ans);
		}
		else if(n%4==3)
		{
			ll t1=a,t2=c+b,t3=3LL*c;
			ll ans=min(t1,t2);
			ans=min(ans,t3);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
