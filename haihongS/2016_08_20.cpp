#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=3e5+9;
const int inf=2e9+9;

int l1,r1,l2,r2;
int num[maxn];

int deal(int x);


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		while(m--){
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int len=r1-l1+1+r2-l2+1;
		if(l1>l2)
			swap(l1,l2);
		if(r1>r2)
			swap(r1,r2);
		if(len&1)
			printf("%.1f\n",1.0*deal((len+1)/2));
		else
			printf("%.1f\n",0.5*deal(len/2)+0.5*deal(len/2+1));
		}
	}
	return 0;
}

int deal(int x)
{
	if(r1<=l2)
	{
		if(r1-l1+1>=x)
			return num[l1+x-1];
		else
		{
			x-=r1-l1+1;
			return num[l2+x-1];
		}
	}
	else
	{
		if(l2-1-l1+1>=x)
			return num[l1+x-1];
		else if(l2-1-l1+1+2*(r1-l2+1)>=x)
		{
			x-=l2-1-l1+1;
			int tmp=(x+1)/2;
			return num[l2+tmp-1];
		}
		else
		{
			x-=r1-l1+1;
			return num[l2+x-1];
		}
	}
}
