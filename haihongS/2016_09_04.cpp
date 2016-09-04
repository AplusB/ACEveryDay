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
const int maxn=5e5+200;
const double eps=1e-9;
const ll inf=2e15+9;
const ll mod=2016;

ll a[maxn],dp[maxn],deq[maxn],s[maxn];

ll getb(int x);
int judge(int x,int y,int z);
ll ff(int j,int x);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		s[0]=0,a[0]=0;
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];

		int ds,dt;
		ds=0,dt=1;
		deq[0]=0;
		
		for(int i=0;i<maxn;i++)
			dp[i]=inf;
		dp[0]=0;
		for(int i=1;i<=n;i++)
		{
			
			while(ds+1<dt && ff(deq[ds+1],i)<=ff(deq[ds],i))
				ds++;
			dp[i]=s[i]+ff(deq[ds],i);

			if(i-k+1>=k)
			{
				while(ds+1<dt && judge(deq[dt-2],deq[dt-1],i-k+1))
					dt--;
				deq[dt++]=i-k+1;
			}
			

		}
		printf("%lld\n",dp[n]);

	}
	return 0;
}

ll ff(int j,int x)
{
	return -a[j+1]*(ll)x+getb(j);
}

int judge(int x,int y,int z)
{
	ll ax=a[x+1],ay=a[y+1],az=a[z+1];
	ll bx=getb(x),by=getb(y),bz=getb(z);
	if((bx-by)*(ay-az)>=(ax-ay)*(by-bz)) return 1;
	//if((ay-ax)*(bz-by)>=(by-bx)*(az-ay)) return 1;
	return 0;
}

ll getb(int x)
{
	return dp[x]-s[x]+a[x+1]*(ll)x;
}
