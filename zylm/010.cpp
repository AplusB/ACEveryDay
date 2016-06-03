//http://codeforces.com/contest/677/problem/B
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
	int n,h,k;
	while(~scanf("%d%d%d",&n,&h,&k))
	{
		int i,j,res=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		long long tmp=0;
		for(i=0;i<n;)
		{
			while(tmp+a[i]<=h && i<n)
			{
				tmp+=(long long)a[i];
				i++;
			}
			if(tmp-k<0)tmp=0;
			 
			res++;
		//	cout<<tmp<<endl;
			
		}
		if(tmp>0)res++;
		
		printf("%d\n",res);
	}
}
