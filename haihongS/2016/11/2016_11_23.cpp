#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const double inf=1e9;
const double eps=1e-12;

struct II
{
	double v;
	double l,r;
}a[maxn];

int n,l;

int judge(double d);
int cmp(II x,II y);

int main()
{
	while(~scanf("%d%d",&n,&l))
	{
		for(int i=0;i<n;i++)
			scanf("%lf",&a[i].v);
		double lt=0,rt=inf,mid,ans=inf;
		for(int i=0;i<2000;i++)
		{
			mid=lt+(rt-lt)/2;
			if(judge(mid)==1)
			{
				ans=min(ans,mid);
				rt=mid;
			}
			else
				lt=mid;
		}
		printf("%.10lf\n",ans);
	}
	return 0;
}

int judge(double d)
{
	for(int i=0;i<n;i++)
	{
		a[i].l=a[i].v-d;
		a[i].r=a[i].v+d;
	}
	sort(a,a+n,cmp);
	int pos=0;
	double now=a[0].l;
	if(now>0) return 0;
	if(a[n-1].r<l && fabs(a[n-1].r-l)>eps) return 0;
	for(int i=0;i<n;i++)
	{
		if(a[i].r<now) continue;
		if(a[i].l>now)
			return 0;
		if(a[i].l<=now) 
			now=max(now,a[i].r);
	}
	return 1;
}

int cmp(II x,II y)
{
	if(x.r==y.r)
		return x.l<y.l;
	return x.r<y.r;
}
