//完全背包nlogn 过了...
#include <iostream>
#include <cstdio>
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
#define INF 0x3f3f3f3f
const double pi = acos(-1.0);
const int mod = 1e9;

const int N =1e6+10;

int dp[N];

void Init()
{
	memset(dp,0,sizeof(dp));
	dp[0]=dp[1]=1;
	for(int i=1;i<=22;i++)
	{
		for(int j=2;j<=1000000;j++)
		{
			int v=1<<(i-1);
			if(j>=v)
				dp[j]=dp[j-v]+dp[j];
			while(dp[j]>mod)
				dp[j]-=mod;
		}
	}
}
int main()
{
	int n;
	Init();
	while(~scanf("%d",&n))
		printf("%d\n",dp[n]);
	return 0;
}



