#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=5e2+9;
const int inf=2e9+9;

double c,d,dAvg;
int n;

struct II
{
	double price,dis;
}a[maxn];

int cmp(II x,II y);

int main()
{
	while(~scanf("%lf%lf%lf%d",&c,&d,&dAvg,&n))
	{
		for(int i=0;i<n;i++)
			scanf("%lf %lf",&a[i].price,&a[i].dis);

		a[n].price=0,a[n].dis=d;
		sort(a,a+n+1,cmp);

		if(a[0].dis!=0)
		{
			printf("The maximum travel distance = 0.00\n");
			continue;
		}

		double pos=0,ans=0,left=0;
		int now=0,flag=0;
		while(pos<d)
		{
			int minn=-1,ok=0;
			for(int i=0;i<=n;i++)
			{
				if(a[i].dis<=pos) continue;
				if(a[i].dis-pos>c*dAvg) break;
				if(a[i].price<=a[now].price)
				{
					ok=1;
					ans+=((a[i].dis-pos)/dAvg-left)*a[now].price;
					left=0;
					pos=a[i].dis;
					now=i;
					break;
				}
				if(minn==-1) minn=i;
				else if(a[i].price<a[minn].price) minn=i;
			}
			if(ok==1) continue;
			if(minn==-1)
			{
				ans=pos+c*dAvg;
				flag=1;
				break;
			}
			ans+=(c-left)*a[now].price;
			left=c-(a[minn].dis-pos)/dAvg;
			pos=a[minn].dis;
			now=minn;
		}
		if(flag) printf("The maximum travel distance = %.2lf\n",ans);
		else printf("%.2lf\n",ans);
	}
	return 0;
}

int cmp(II x,II y)
{
	return x.dis<y.dis;
}
