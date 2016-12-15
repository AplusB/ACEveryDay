#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e6+60;
const int inf=1e6;

struct II
{
	int nx,last;
}num[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(num,-1,sizeof(num));
		for(int i=0;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			num[u].nx=v;
			num[v].last=u;
		}
		if(n%2==0){
		int f2=0;
		while(num[f2].last!=-1)
			f2=num[f2].last;
		int f1=num[0].nx;
		int use=0;
		while(f1!=-1 || f2!=0)
		{
			if(f2!=0)
			{
				if(use!=0) printf(" ");
				use=1;
				printf("%d",f2);
				f2=num[f2].nx;
			}
			if(f1!=-1) 
			{
				if(use!=0) printf(" ");
				use=1;
				printf("%d",f1);
				f1=num[f1].nx;
			}
		}
		printf("\n");
		}
		else
		{
			int f2;
			for(int i=0;i<=inf;i++)
			{
				if(num[i].nx==-1 && num[i].last!=-1)
				{
					f2=i;break;
				}
			}
			while(num[f2].last!=-1) f2=num[f2].last;
			int f1=num[0].nx;
			int use=0;
			while(f2!=-1 || f1!=0)
			{
				if(f2!=-1)
				{
					if(use!=0) printf(" ");
					use=1;
					printf("%d",f2);
					f2=num[f2].nx;
				}
				if(f1!=0)
				{
					if(use!=0) printf(" ");
					use=1;
					printf("%d",f1);
					f1=num[f1].nx;
				}
				
			}
			printf("\n");
		}
	}
	return 0;
}

