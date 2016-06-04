//http://codeforces.com/contest/677/problem/B 数据范围
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 100005
using namespace std;
int a[maxn];

int main()
{
//	read;
	std::ios::sync_with_stdio(false);
	LL n,h,k;
	while(~scanf("%I64d%I64d%I64d",&n,&h,&k))
	{
		int i,j;
		LL res=0;
		for(i=0;i<n;i++)
			scanf("%I64d",&a[i]);
		long long tmp=0;
		for(i=0;i<n;)
		{
			int flag=0;
			while(tmp+a[i]<=h && i<n)
			{
				tmp+=(long long)a[i];
				i++;
				flag=1;
			}
			if(flag)
			{
				res+= tmp/k;
			    tmp%=k; 
			}
			else 
			{
				res++;
				tmp=0;
		    }
			 
		}
		if(tmp>0)res++;
		
		printf("%I64d\n",res);
	}
}
