//http://codeforces.com/contest/675/problem/B
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
	std::ios::sync_with_stdio(false);
	int  n,a,b,c,d,i,j;
	while(~scanf("%d%d%d%d%d",&n,&a,&b,&c,&d))
	{
		long long cnt=0;
		for(i=1;i<=n;i++)
		{
			int y=i+b-c,z=i+a-d,k=i+a+b-c-d;
			if(y<=n && y>=1 && z<=n && z>=1 && k>=1 && k<=n)cnt++;
		}
		printf("%I64d\n",(long long)cnt*n);
	 } 
}
