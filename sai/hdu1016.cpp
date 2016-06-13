#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int is_prime[40];
int loop[25];
int vis[25];
int cnt,n;

void init()
{
	memset(is_prime,0,sizeof(is_prime));
	memset(loop,0,sizeof(loop));
	memset(vis,0,sizeof(vis));

	loop[1]=1;
	vis[1]=1;

	for(int i=2;i<=40;i++)
	{
		int flag=0;
		for(int j=2;j*j<=i;j++)
		{
			if(i%j==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			is_prime[i]=1;
		}
	}
}

void output()
{
	cout<<loop[1];
	for(int i=2;i<=n;i++)
	{
		cout<<" "<<loop[i];
	}
	cout<<endl;
}

void dfs(int x)
{
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0&&is_prime[i+loop[x-1]]==1)
		{
			loop[x]=i;
			vis[i]=1;

			if(x==n&&is_prime[i+1]==1)
			{
				output();
				vis[i]=0;
				loop[x]=0;
				continue;
			}

			dfs(x+1);
			vis[i]=0;
			loop[x]=0;
		}
	}
}

int main()
{
	int z=1;
	while(cin>>n)
	{
		init();
		printf("Case %d:\n",z++);
		dfs(2);
		cout<<endl;
	}
	return 0;
}
