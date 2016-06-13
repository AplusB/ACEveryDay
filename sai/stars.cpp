#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

#define maxn 32005

int bit[32005];
int lev[32005];

void add(int i,int x)
{
	while(i<=maxn)
	{
		bit[i]+=x;
		i+=(i&-i);
	}
}

int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=(i&-i);
	}
	return s;
}

int main()
{
	int t;
	while(cin>>t)
	{
		memset(bit,0,sizeof(bit));
		memset(lev,0,sizeof(lev));
		int x,y;

		for(int i=0;i<t;i++)
		{
			scanf("%d%d",&x,&y);
			lev[sum(x+1)]++;
			add(x+1,1);
		}

		for(int i=0;i<t;i++)
		{
			cout<<lev[i]<<endl;
		}
	}
	return 0;
}
