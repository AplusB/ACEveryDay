/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月26日 星期四 22时10分13秒
File Name     :main.cpp
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
const int maxn=1e5+9;
const int inf=1e9+9;

int num[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) scanf("%d",&num[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				int tmp=0;
				for(int k=i;k<=j;k++)
				{
					tmp+=1-num[k];
				}
				for(int k=1;k<=i-1;k++)
					tmp+=num[k];
				for(int k=j+1;k<=n;k++)
					tmp+=num[k];
				ans=max(ans,tmp);
			}
		}
		printf("%d\n",ans);
	}

    return 0;
}
