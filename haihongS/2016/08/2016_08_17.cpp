#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=30+9;
const int inf=2e9+9;

int gcd(int a,int b);

int main()
{
	int a[10];
	for(int i=0;i<4;i++)
		scanf("%d",&a[i]);
	int all;
	scanf("%d",&all);
	int ans=0;
	for(int i=0;i<(1<<4);i++)
	{
		int sum=1,cnt=0;
		for(int j=0;j<4;j++)
		{
			if(i&(1<<j))
			{
				int tmp=sum*a[j];
				tmp/=gcd(sum,a[j]);
				sum=tmp;
				cnt++;
			}
		}
		sum=all/sum;
		if(cnt&1)
			ans-=sum;
		else
			ans+=sum;
		//printf("*%d %d %d\n",ans,sum,cnt);
	}
	//printf("%d\n",ans);
	printf("%d\n",all-ans);
	return 0;
}

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
