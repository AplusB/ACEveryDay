/* ***********************************************
Author        :shootPlane
Created Time  :2016/7/5 18:16:09
File Name     :S:\01\main.cpp
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
typedef long long LL;
const int maxn=1e5+9;
const int inf=1e9+9;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		int flag=0;
		for(int i=0;i<109;i++)
		{
			if(flag==1)
				break;
			for(int j=0;j<109;j++)
			{
				if(i*a+b*j==c)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
    return 0;
}
