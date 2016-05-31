#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=1500+10;
vector<int>v[N];
int all[N],dp[N];

void dfs(int x,int fa)
{
	int tmp=0;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa) continue;
		dfs(y,x);
		tmp+=dp[y];
		dp[x]+=all[y];
	}
	all[x]=min(dp[x],tmp);
}

int main()
{
    int _,n,m,i,j,a,b;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
		{
			v[i].clear();
			all[i]=0;
			dp[i]=1;
    	}
		for(i=0;i<n;i++)
        {
            scanf("%d:(%d)",&a,&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&b);
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        dfs(0,-1);
        printf("%d\n",all[0]);
    }
    return 0;
}
