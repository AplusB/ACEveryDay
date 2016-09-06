#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const double eps=1e-9;
const ll inf=2e15+9;
const ll mod=2016;

ll num[maxn];

int main()
{
	int n;
	ll a;
	while(~scanf("%d%lld",&n,&a))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&num[i]);
		sort(num+1,num+1+n);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		if(a<=num[1])
		{
			printf("%lld\n",num[n-1]-a);continue;
		}
		else if(num[n]<=a)
		{
			printf("%lld\n",a-num[2]);continue;
		}
		ll ans=inf;
		int fir;
		for(int i=n;i>=1;i--)
		{
			if(num[i]<=a)
			{
				fir=i;break;
			}
		}
		for(int i=fir;i>=1;i--)
		{
			ll go=0;
			int lt=fir-i+1;
			if(lt>n-1) break;
			go+=a-num[i];
			int rt=n-1-lt;
			if(rt>n-fir) continue;
			if(rt>0)
				go+=num[fir+rt]-num[i];
			ans=min(ans,go);
		}
		fir+=1;
		for(int i=fir;i<=n;i++)
		{
			ll go=0;
			int rt=i-fir+1;
			if(rt>n-1) break;
			go+=num[i]-a;
			int lt=n-1-rt;
			if(lt>fir-1) continue;
			if(lt>0)
				go+=num[i]-num[fir-lt];
			ans=min(ans,go);
		}

		printf("%lld\n",ans);
		
	}
	return 0;
}
