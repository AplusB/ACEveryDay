#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 9;
const ll inf = 2e9 + 9;

typedef pair<double,double> P;

ll a[maxn];
int n,k,flag[maxn];

int deal(ll v);

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		ll lt=1,rt=inf,mid,ans=inf;
		while(lt<=rt)
		{
			mid=lt+(rt-lt)/2;
			//printf("*%lld\n",mid);
			if(deal(mid))
			{
				ans=min(ans,mid);
				rt=mid-1;
			}
			else lt=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

int deal(ll v)
{
	memset(flag,0,sizeof(flag));
	int sum=k,pos=0;
	for(int i=n-1;i>=0;i--)
	{
		if(sum==0) break;
		if(flag[i]==1) continue;
		if(i<pos) break;
		if(a[i]>v) break;
		flag[i]=1;
		sum--;
		if(i!=pos && v-a[i]>=a[pos])
		{
			flag[pos]=1;
			pos++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0) return 0;
	}
	return 1;
}
