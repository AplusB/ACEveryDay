//转化成A+B=X-C搞，然后（A+B）搞个数组，遍历一下X-C,二分搜索一下，妥妥的不会超时。

#include<cstdio>
#include<queue>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define N 505 

int num;
__int64 ad[N*N];

int solve(__int64 x)
{
	int mid;
	int be,ed;
	be=0;
	ed=num-1;
	while(be<=ed)
	{
		mid=(be+ed)/2;
 
		if(ad[mid]<x)
			be=mid+1;
		else if(ad[mid]>x)
			ed=mid-1;
		else
			return 1;
	}
	return 0;
}

int main()
{
	int n,m,d;
	int cnt=1;
	__int64 a[N];
	__int64 c[N];
	__int64 b[N];
	while(~scanf("%d%d%d",&n,&m,&d))
	{
		for(int i=1;i<=n;i++)
			scanf("%I64d",&a[i]);

		for(int i=1;i<=m;i++)
			scanf("%I64d",&b[i]);
		
		for(int i=0;i<d;i++)
			scanf("%I64d",&c[i]);
		
		num=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				ad[num++]=a[i]+b[j];
			}
		}
		
		sort(ad,ad+num);
		sort(c,c+d);
		
		cout<<"Case "<<cnt++<<":"<<endl;
		int T;
		scanf("%d",&T);
		
		for(int i=1;i<=T;i++)
		{
			int x,y;
			scanf("%I64d",&x);
			
			if(x<(ad[0]+c[0])||x>(ad[num-1]+c[d-1]))
			{
				cout<<"NO"<<endl;
				continue;
			}
			int flag=0;
			for(int j=0;j<d;j++)
			{
				y=solve(x-c[j]);
				if(y)
				{
					flag=1;
					break;
				}
			}
			
			if(flag)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
}
 


