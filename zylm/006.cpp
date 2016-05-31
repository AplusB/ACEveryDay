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
	int n;
	while(~scanf("%d",&n))
	{
		int tmp = n/7,mod=n%7;
		if(tmp==0)
		{
			if(n>5)printf("%d %d\n",n%5,min(mod,2));
			else printf("0 %d\n",min(mod,2));
		}
		else printf("%d %d\n",tmp*2+mod/6,tmp*2+min(2,mod));
	 } 
}
