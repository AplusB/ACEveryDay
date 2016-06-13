//http://codeforces.com/contest/680/problem/A
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
int main()
{
	int t[5];
	while(~scanf("%d%d%d%d%d",&t[0],&t[1],&t[2],&t[3],&t[4]))
	{
		int i,j,sum=0;
		map<int,int> mp;
		for(i=0;i<5;i++)sum+=t[i],mp[t[i]]++;
		int mmin=9000;
		for(i=0;i<5;i++)
		{
			if(mp[t[i]]>=2)
			    mmin=min(mmin,sum-t[i]*2);
			if(mp[t[i]]>=3)
			    mmin=min(mmin,sum-t[i]*3);
		}
		printf("%d\n",min(mmin,sum));
	 } 
}
