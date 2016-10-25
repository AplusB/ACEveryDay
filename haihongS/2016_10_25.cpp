#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int a[maxn][4];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		memset(a,0,sizeof(a));
		int pos=0,flag=0;
		int now;
		for(now=1;now<=m;now++)
		{
			if(flag==0) pos++;
			if(pos>n) break;
			a[pos][flag]=now;
			if(flag==0) flag=3;
			else flag=0;
		}
		if(pos>n)
		{
			pos=0,flag=1;
			for(;now<=m;now++)
			{
				if(flag==1) pos++;
				a[pos][flag]=now;
				if(flag==1) flag=2;
				else flag=1;
			}
		}
		int use=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]!=0)
			{
				if(use==1) printf(" ");
				printf("%d",a[i][1]);use=1;
			}
			if(a[i][0]!=0)
			{
				if(use==1) printf(" ");
				printf("%d",a[i][0]);use=1;
			}
			if(a[i][2]!=0)
			{
				if(use==1) printf(" ");
				printf("%d",a[i][2]);use=1;
			}
			if(a[i][3]!=0)
			{
				if(use==1) printf(" ");
				printf("%d",a[i][3]);use=1;
			}
		}
		printf("\n");

	}
	return 0;
}
