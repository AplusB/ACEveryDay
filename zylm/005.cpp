#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 105
using namespace std;
int a[maxn];

int main()
{
	std::ios::sync_with_stdio(false);
	int n,i,j;
	while(~scanf("%d",&n))
	{
		int res=0;
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		for(i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]>15)
			{
				res=a[i-1]+15;
				break;
			}
		}
		if(res==0)res=min(a[n]+15,90);
		printf("%d\n",res);
		
	}
	 
}
