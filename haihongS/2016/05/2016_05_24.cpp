/* ***********************************************
Author        :shootPlane
Created Time  :2016/5/24 15:42:39
File Name     :D:\sherlock\main.cpp
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
const int maxn=1e2+9;
const int inf=1e9+9;

int c[maxn];
double dp[200*maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,f;
	while(~scanf("%d%d",&n,&f))
	{
		int up=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			up=max(up,c[i]);
		}
		memset(dp,0,sizeof(dp));
		double oo=0;
		for(int i=1;i<=n;i++)
		{
			double xx=(1+sqrt(5))/2*(double)(c[i]*c[i]);
			ll yy=xx*100000;
			yy/=100000;
			oo+=(double)yy;
		}
		oo/=n;
		oo+=1;

		for(int i=up+1;i<=2*up;i++) dp[i]=oo;

		for(int i=up;i>=f;i--)
		{
			double tmp=0;
			for(int j=1;j<=n;j++)
			{
				if(i>c[j])
				{
					double xx=(1+sqrt(5))/2*(double)(c[j]*c[j]);
					ll yy=xx*100000;
					yy/=100000;
					tmp+=(double)yy;
				}
				else
				{
					tmp+=dp[i+c[j]];
				}
			}
			dp[i]=1+tmp/(double)n;
		}
		printf("%.3lf\n",dp[f]-1);
	}
    return 0;
}
