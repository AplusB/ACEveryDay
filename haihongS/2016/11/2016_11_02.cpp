#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+8;

int a[maxn];
int cnt[maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		//init
		for(int i=0;i<maxn;i++)
		{
			cnt[i]=a[i]=0;
		}
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		for(int i=1;i<maxn;i++)
		{
			for(int j=i;j<maxn;j+=i)
			{
				cnt[i]+=a[j];
			}
		}
		ll ans=0;
		for(int i=0;i<maxn;i++)
		{
			if(a[i]==0) continue;
			int v=i;
			int go[10],pos=0;
			for(int j=2;j*j<=i && v>1;j++)
			{
				if(v%j==0)
				{
					go[pos++]=j;
					while(v%j==0) v/=j;
				}
			}
			if(v>1)
				go[pos++]=v; 
			if(pos==0) continue;
			int sum=0;
			int len=1<<pos;
			for(int j=1;j<len;j++)
			{
				int tmp=0,now=1;
				for(int k=0;k<pos;k++)
				{
					if((1<<k)&j)
					{
						tmp++;
						now*=go[k];
					}
				}
				if(tmp&1) sum+=cnt[now];
				else sum-=cnt[now];
			}
			sum=n-sum;
			ans+=1LL*(sum)*max(0,(n-sum-1));
		}
		ans/=2;
		ll pp=1LL*n;
		ans=pp*(pp-1)*(pp-2)/6-ans;
		printf("%lld\n",ans);
	}
	return 0;
}
