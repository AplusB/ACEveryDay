#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>


using namespace std;
typedef long long ll;
const int maxn=2e2+9;
const ll inf=2e16+9;
const ll mod=1e9+7;
double eps=1e-6;
double pi=acos(-1.0);


int main()
{
	freopen("subtlesabotage.in","r",stdin);
	freopen("bb.out","w",stdout);
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m,k;
		scanf("%lld%lld%lld",&n,&m,&k);
		printf("Case #%d: ",cas++);
		if(m>n) swap(n,m);
		ll ans=inf;
		if(2*k+1<=m && 2*k+3<=n)
		{
			ll tmp=2+ceil(1.0*(k+2)/k);
			ans=min(ans,tmp);
		}
		if(2*k+3<=n && k+1<=m)
		{
			ll tmp=1+ceil(1.0*(m-k)/k);
			ans=min(ans,tmp);
		}
		if(ans==inf) printf("-1\n");
		else printf("%lld\n",ans);

	}
	return 0;
}
