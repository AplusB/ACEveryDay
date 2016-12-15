/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月17日 星期二 22时27分06秒
File Name     :3071.cpp
Blog          :http://haihongblog.com
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn=3e2+9;
const int inf=1e9+9;

double p[maxn][maxn];
double dp[maxn][maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(scanf("%d",&n) && n!=-1)
	{
		int len=1<<n;
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				scanf("%lf",&p[i][j]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<len;i++)
			dp[0][i]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<len;j++)
			{
				for(int k=0;k<len;k++)
				{
					if((j>>i)==(k>>i))
					{
						if(j>>(i-1)!=(k>>(i-1)))
						{
							dp[i][j]+=dp[i-1][j]*dp[i-1][k]*p[j][k];
						}
					}
				}
			}
		}
		double maxx=0;
		int ans;
		for(int i=0;i<len;i++)
		{
			if(dp[n][i]>maxx)
			{
				maxx=dp[n][i];ans=i;
			}
		}
		printf("%d\n",ans+1);
	}

    return 0;
}
