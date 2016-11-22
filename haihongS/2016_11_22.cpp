#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;

ll x[maxn],y[maxn];
int p1,p2;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		p1=0,p2=0;
		ll v1=0,v2=0;
		ll last=0;
		for(int i=0;i<n;i++)
		{
			ll v;
			scanf("%lld",&v);
			if(v>0)
			{
				v1+=v;
				x[p1++]=v;
			}
			else
			{
				v2+=-v;
				y[p2++]=-v;
			}
			if(i==n-1) last=v;
		}
		if(v1>v2)
			printf("first\n");
		else if(v1<v2)
			printf("second\n");
		else
		{
			int len=min(p1,p2);
			int flag=0;
			for(int i=0;i<len;i++)
			{
				if(x[i]>y[i])
				{
					flag=1;break;
				}
				else if(x[i]<y[i])
				{
					flag=-1;break;
				}
			}
			if(flag==0)
			{
				if(p1>p2) flag=1;
				else if(p1<p2) flag=-1;
			}
			if(flag!=0)
			{
				if(flag==1) printf("first\n");
				else printf("second\n");
				continue;
			}
			if(last<0) flag=-1;
			else flag=1;
			if(flag==1) printf("first\n");
			else printf("second\n");
		}

	}
	return 0;
}
