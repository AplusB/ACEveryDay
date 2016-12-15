#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=1000000;

int num[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=n;j>i;j--)
			{
				if(num[j]<num[j-1])
				{
					printf("%d %d\n",j-1,j);
					swap(num[j],num[j-1]);
				}
			}
		}
	}
	return 0;
}
