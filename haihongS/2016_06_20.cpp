/* ***********************************************
Author        :shootPlane
Created Time  :2016/6/20 11:07:15
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
typedef long long ll;
const int maxn=3e5+9;
const int inf=1e9+9;

char num[maxn];
int flag[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	while(~scanf("%s",num))
	{
		int len=strlen(num);
		ll ans=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<len;i++)
		{
			if(i==0)
			{
				int tmp=num[i]-'0';
				if(tmp%4==0) flag[i]=1;
				continue;
			}
			int tmp=num[i]-'0'+10*(num[i-1]-'0');
			if(tmp%4==0) flag[i]=1;
		}
		for(int i=0;i<len;i++)
		{
			if((num[i]-'0')%4==0) ans+=1;
			if(flag[i]==1)
			{
				ans+=(ll)i;
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}
