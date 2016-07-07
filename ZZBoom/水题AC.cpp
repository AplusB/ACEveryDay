//hdoj  1051
//先排序，然后就可以贪心了。

#include<cstdio>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define N 5010

struct asd{
	int ll;
	int ww;
	int flag;
};
asd q[N];
bool cmp(asd z,asd x)
{
	if(z.ll<x.ll)
	return 1;
	else if(z.ll==x.ll)
	{
		return z.ww<x.ww;
	}
	return 0;
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,cnt;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&q[i].ll,&q[i].ww);
			q[i].flag=0;
		}
		sort(q,q+n,cmp);
		
		if(!n)
		{
			puts("0");
			continue;
		}
		cnt=0;
		int k;
		
		for(int i=0;i<n;i++)
		{
			if(q[i].flag)
			continue;
			
			cnt++;k=i;
			for(int j=i+1;j<n;j++)
			{
				if(q[j].ll>=q[k].ll&&q[j].ww>=q[k].ww&&!q[j].flag)
				{
					q[j].flag=1;
					k=j;
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}


