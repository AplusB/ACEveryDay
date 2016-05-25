//hdoj3461

#include<cstdio>
#include<queue>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define mod 1000000007
#define N 10000010

int pre[N];

int n,sum;

void init()
{
	sum=n;
	for(int i=0;i<=n;i++)
		pre[i]=i;
}

int Find(int x)
{
	int r;
	r=x;
	while(pre[r]!=r)
	{
		r=pre[r];
	}
	int i=x,j;
	while(pre[i]!=r)
	{
		j=pre[i];
		pre[i]=r;
		i=j;
	}
	return r;
}

void solve(int a,int b)
{
	a=Find(a);
	b=Find(b);
//	printf("%d%d\n",a,b);
	if(a==b)
		return;
	pre[a]=b;
	sum--;
}

void fast_gg()
{
	long long ans=1;
	long long p=26;
//	printf("%d\n",sum);
	while(sum>0)
	{
		if(sum%2==1)
		{
			ans=(ans*p)%mod;
		}
		p=(p*p)%mod;
		sum=sum/2;
	}
	printf("%I64d\n",ans);
}

int main()
{
	int m;
	while(~scanf("%d%d",&n,&m))
	{
		int a,b;
		init();
	//	for(int i=0;i<=n;i++)
	//		cout<<pre[i]<<endl;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			solve(a-1,b);
		}
		fast_gg();
	}	
	return 0;
} 

 

