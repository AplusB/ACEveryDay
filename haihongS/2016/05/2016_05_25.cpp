/* ***********************************************
Author        :shootPlane
Created Time  :2016年05月25日 星期三 22时30分37秒
File Name     :466c.cpp
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
const int maxn=5e5+9;
const int inf=1e9+9;

ll num[maxn];
ll pre[maxn],last[maxn];
ll flag[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n;
	while(~scanf("%d",&n))
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			sum+=num[i];
		}
		if(n<3 || sum%3!=0)
		{
			printf("0\n");continue;
		}
		ll tmp=sum/3;
		memset(flag,0,sizeof(flag));
		pre[0]=0;
		ll cnt=0;
		flag[0]=0;
		for(int i=1;i<=n;i++)
		{
			pre[i]=pre[i-1]+num[i];
			if(tmp==pre[i])
			{
				flag[i]=++cnt;
			}
			else 
				flag[i]=flag[i-1];
		}
		last[n+1]=0;
		ll ans=0;
		for(int i=n;i>=1;i--)
		{
			last[i]=last[i+1]+num[i];
			if(tmp==last[i])
			{
				ans+=flag[i-2];
			}
		}
		printf("%lld\n",ans);
		
	}
    return 0;
}
