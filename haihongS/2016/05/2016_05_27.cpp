/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月27日 星期五 13时57分43秒
File Name     :148d.cpp
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
const int maxn=1e3+9;
const int inf=1e9+9;

double dp[maxn][maxn][2];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int w,b;
	while(~scanf("%d%d",&w,&b))
	{
		memset(dp,0,sizeof(dp));

		dp[1][0][1]=1,dp[3][0][0]=1;
		for(int i=1;i<=w;i++)
			dp[i][0][1]=1;

		for(int i=0;i<=w;i++)
		{
			for(int j=0;j<=b;j++)
			{
				double t1=1.0*j/(i+j),t2=1.0*(j-1)/(i+j-1),t3=1.0*i/(i+j-1);
				if(i!=0 && j!=0 && j!=1)
					dp[i][j][0]=t1*(t2*dp[i][j-2][1]+t3*dp[i-1][j-1][1]);

				if(j!=0)
					dp[i][j][1]=1.0*i/(i+j)+1.0*j/(i+j)*dp[i][j-1][0];
			}
		}
		printf("%.9lf\n",dp[w][b][1]);
	}
    return 0;
}
