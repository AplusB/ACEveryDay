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
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

ll a[maxn],rec[2*maxn];

int bi(int lt,int rt,ll v);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(rec,0,sizeof(rec));
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		ll ans=0;
		for(int i=0;i<n;i++)
		{
			if(rec[a[i]]==1) continue;
			ll now=0;
			for(ll j=a[i];j<=a[n-1];j+=a[i])
			{
				rec[j]=1;
				int lt=bi(0,n-1,j+a[i]);
				int rt=bi(0,n-1,j);
				now+=j*(lt-rt);
			}
			ans=max(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

int bi(int lt,int rt,ll v)
{
	int mid,ans=rt+1;
	while(lt<=rt)
	{
		mid=lt+(rt-lt)/2;
		if(a[mid]>=v)
		{
			ans=min(ans,mid);
			rt=mid-1;
		}
		else
			lt=mid+1;
	}
	return ans;
}
