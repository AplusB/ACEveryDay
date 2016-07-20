#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;

int num[maxn];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2*m;j++)
			{
				scanf("%d",&num[j]);
				if(j&1)
				{
					if(num[j]==1 || num[j-1]==1)
						ans++;
				}
			}
		}
		printf("%d\n",ans);

	}
	return 0;
}
