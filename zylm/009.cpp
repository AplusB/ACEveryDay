//http://codeforces.com/contest/677/problem/A
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 1005
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n,h;
	int a;
	while(~scanf("%d%d",&n,&h))
	{
		int i,j,res=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(a>h)res+=2;
			else res+=1;
		}
		printf("%d\n",res);
	}
}

