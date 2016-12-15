/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月08日 星期日 20时04分50秒
File Name     :2441.cpp
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
const int maxn=21;
const int inf=1e9+9;

vector<int> aha[maxn];
int dp[2][1<<maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
		{
			aha[i].clear();
			int p;
			scanf("%d",&p);
			for(int j=0;j<p;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				tmp--;
				aha[i].push_back(tmp);
			}
		}
		memset(dp,0,sizeof(dp));
		int *ff=dp[0], *next=dp[1];
		for(int i=0;i<aha[1].size();i++)
		{
			dp[0][1<<aha[1][i]]=1;
		}

		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<(1<<m);j++)
			{
				if(ff[j]==0) continue;
				int len=aha[i].size();
				for(int k=0;k<len;k++)
				{
					int v=aha[i][k];
					if(((1<<v)&j)==0)
					{
						next[j|(1<<v)]+=ff[j];
					}
				}
			}
			swap(ff,next);
			for(int j=0;j<(1<<m);j++)
				next[j]=0;
		}
		int ans=0;
		for(int i=0;i<(1<<m);i++)
			ans+=ff[i];
		printf("%d\n",ans);

	}
    return 0;
}
