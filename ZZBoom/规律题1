//hdoj2802

//规律题一般策略 
//1.打表，观察。
//2.直接写个程序判断哪个地方循环。 

#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

#define N 100010

using namespace std;

const int mod=2009;

int f[5000];

int Get(int x)
{
	int part1=((x*x)%mod*x)%mod;
	int y=x-1;
	int part2=((y*y)%mod*y)%mod;
	return ((f[x-2]+part1)%mod+mod-part2)%mod;
}

int main()
{

	int n;
	f[1]=1; f[2]=7;
	for(int i=3;i<=4018;i++) 
		f[i]=Get(i);

	while(scanf("%d",&n)!=EOF&&n)
	{
		n=n%4018;
		if(n==0) puts("0");
		else printf("%d\n",f[n]);
	}

    return 0;
}
