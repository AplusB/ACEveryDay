#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e2+60;
const double inf=1e9;
const double eps=1e-12;

int a1[maxn],a2[maxn];

int main()
{
	int m,s;
	while(~scanf("%d%d",&m,&s))
	{
		if(m==1 && s==0)
		{
			printf("0 0\n");continue;
		}
		if(!(1<=s && s<=9*m))
		{
			printf("-1 -1\n");continue;
		}

		int p1=0,p2=0;

		int v=s;
		a1[p1++]=max(1,v-(m-1)*9);
		v-=a1[p1-1];
		while(p1<m)
		{
			int lt=m-p1-1;
			lt*=9;
			int now;
			if(v-lt<=0)
			{
				a1[p1++]=0;
			}
			else
			{
				a1[p1++]=v-lt;
				v-=a1[p1-1];
			}
		}

		v=s;
		a2[p2++]=min(9,s);
		v-=a2[p2-1];
		while(p2<m)
		{
			if(v>=9)
			{
				a2[p2++]=9;
				v-=9;
			}
			else
			{
				a2[p2++]=v;
				v=0;
			}
		}
		for(int i=0;i<m;i++)
			printf("%d",a1[i]);
		printf(" ");
		for(int i=0;i<m;i++)
			printf("%d",a2[i]);
		printf("\n");

	}
	return 0;
}
