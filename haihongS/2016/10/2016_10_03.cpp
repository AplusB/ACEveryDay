#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn=200+9;
const ll inf=2e14+9;

struct II
{
	int u,d,l,r,v;
}s[maxn*maxn];

void output(int n,int fir);

int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int now=i*n+j;

				s[now].v=now;
				s[now].l=i*n+(j-1+n)%n;
				s[now].r=i*n+(j+1+n)%n;
				s[now].u=(i-1+n)%n*n+j;
				s[now].d=(i+1+n)%n*n+j;
			}
		}
		int fir=0;
		while(q--)
		{
			int t,l,r,d;
			scanf("%d%d%d%d",&t,&l,&r,&d);
			if(t==1)
			{
				int now=fir;
				for(int i=0;i<l;i++)
					now=s[now].d;
				int p1=now,p2=now;
				int re[maxn];
				for(int i=0;i<d;i++) p2=s[p2].r;
				for(int i=0;i<n;i++)
				{
					re[i]=s[p1].u;
					p1=s[p1].r;
				}
				for(int i=0;i<n;i++)
				{
					s[p2].u=re[i];
					s[re[i]].d=p2;
					p2=s[p2].r;
				}
				if(l==0) fir=s[re[0]].d;

				for(int i=l+1;i<=r;i++) now=s[now].d;
				p1=p2=now;
				for(int i=0;i<d;i++) p2=s[p2].r;
				for(int i=0;i<n;i++)
				{
					re[i]=s[p1].d;
					p1=s[p1].r;
				}
				for(int i=0;i<n;i++)
				{
					s[p2].d=re[i],s[re[i]].u=p2;
					p2=s[p2].r;
				}
			}
			else
			{
				int now=fir;
				for(int i=0;i<l;i++)
					now=s[now].r;
				int p1=now,p2=now;
				int re[maxn];
				for(int i=0;i<d;i++) p2=s[p2].d;
				for(int i=0;i<n;i++)
				{
					re[i]=s[p1].l;
					p1=s[p1].d;
				}
				for(int i=0;i<n;i++)
				{
					s[p2].l=re[i],s[re[i]].r=p2;
					p2=s[p2].d;
				}
				if(l==0) fir=s[re[0]].r;

				for(int i=l+1;i<=r;i++) now=s[now].r;
				p1=p2=now;
				for(int i=0;i<d;i++) p2=s[p2].d;
				for(int i=0;i<n;i++)
				{
					re[i]=s[p1].r;
					p1=s[p1].d;
				}
				for(int i=0;i<n;i++)
				{
					s[p2].r=re[i],s[re[i]].l=p2;
					p2=s[p2].d;
				}
			}
		}
		output(n,fir);
	}
	return 0;
}

void output(int n,int fir)
{
	for(int i=0;i<n;i++)
	{
		int now=fir;
		for(int j=0;j<n;j++)
		{
			if(j!=0) printf(" ");
			printf("%d",s[now].v);
			now=s[now].r;
		}
		printf("\n");
		fir=s[fir].d;
	}
	printf("\n");
}
