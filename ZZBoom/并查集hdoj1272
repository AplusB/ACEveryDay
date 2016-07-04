#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

#define N 100020

int pre[N];
bool vis[N];

void init()
{
	for(int i=1;i<=100000;i++)
		pre[i]=i;
	memset(vis,0,sizeof(vis));
}
int Find(int u)
{
	int r=u;
	while(r!=pre[r])
	{
		r=pre[r];
	}
	int i=u,j;
	while(pre[i]!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

int main()
{
	int a,b,aa,bb;
	while(1)
	{
		init();
		int flag=0;
		scanf("%d%d",&a,&b);
		if(a==-1&&b==-1)
			break;
		if(!a&&!b)
		{
			printf("Yes\n");
			continue;	
		}
		vis[a]=vis[b]=1;
		aa=Find(a);
		bb=Find(b);
		if(aa!=bb)
			pre[aa]=bb;
		else
			flag=1;
		
		while(1)
		{
			scanf("%d%d",&a,&b);
			if(!a&&!b)
				break;
			vis[a]=vis[b]=1;
			aa=Find(a);
			bb=Find(b);
			if(aa!=bb)
				pre[aa]=bb;
			else
				flag=1;
		}
		int cnt=0;
		for(int i=1;i<=100000;i++)
		{
			if(pre[i]==i&&vis[i])
			{
				cnt++;
			}
		}
		if(!flag&&cnt==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}






