#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

#define N 100010


int n,k;

int st[N];
bool vis[N];
//int q[N];
queue<int>q;

void BFS()
{
	memset(vis,0,sizeof(vis));
	memset(st,0,sizeof(st));
	while(!q.empty())
		q.pop();
	
	q.push(n);
	vis[n]=1;
	
	while(!q.empty())
	{
		int u=q.front();
		if(u==k)
		{
			printf("%d\n",st[u]);
			return;
		}
		q.pop();
		
		for(int i=0;i<3;i++)
		{
			int m;
			if(i==0)
			{
				m=u-1;
			}
			if(i==1)
			{
				m=u+1;
			}
			if(i==2)
			{
				m=u*2;
			}
			if(m<0||m>100000||vis[m])
				continue;
			q.push(m);
			vis[m]=1;
			st[m]=st[u]+1;
		}
	}
}
/*
void BFS()
{
	memset(vis,0,sizeof(vis));
	memset(st,0,sizeof(st));
	int head,tail;
	head=0;
	tail=1;
	
	q[head]=n;
	vis[n]=1;
	
	while(head<tail)
	{
		int u=q[head];
		if(u==k)
		{
			printf("%d\n",st[u]);
			return;
		}
		head++;
		
		for(int i=0;i<3;i++)
		{
			int m;
			if(i==0)
			{
				m=u-1;
			}
			if(i==1)
			{
				m=u+1;
			}
			if(i==2)
			{
				m=u*2;
			}
			if(m<0||m>100000||vis[m])
				continue;
			q[tail++]=m;
			vis[m]=1;
			st[m]=st[u]+1;
		}
	}
}

*/
int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		BFS();	
	}
	return 0;
}
