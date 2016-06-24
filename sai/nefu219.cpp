#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

struct robot{
	int x,y;
}r[505];

int vis[505];

bool cmp(robot a,robot b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==-1&&b==-1)break;

		memset(vis,0,sizeof(vis));
		int i=0;
		while(a+b)
		{
			r[i].x=a;
			r[i].y=b;
			i++;
			cin>>a>>b;
		}

		sort(r,r+i,cmp);

		int sum=i;
		int cnt=0;
		while(sum>0)
		{
			int tx=0;
			int ty=0;
			for(int j=0;j<i;j++)
			{
				if(vis[j]==0&&r[j].x>=tx&&r[j].y>=ty)
				{
					tx=r[j].x;
					ty=r[j].y;
					vis[j]=1;
					sum--;
				}
			}
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
