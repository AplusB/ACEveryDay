//http://codeforces.com/contest/680/problem/B
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
	int n,pos;
	while(~scanf("%d%d",&n,&pos))
	{
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		int res=0;
		for(i=1;i<n;i++)
		{
			int f1=0,f2=0;
			if(i+pos<=n )f1=1;
			if(pos-i>0  )f2=1;
			if(f1&&!f2)
			{
				if(a[i+pos])res++;
			}
			else if(!f1&&f2)
			{
				if(a[pos-i])res++;
			}
			else if(f1&&f2)
			{
				if(a[i+pos] && a[pos-i])res+=2;
			}
		}
		if(a[pos])res++;
		 
		printf("%d\n",res);
		
	 } 
	
}
