#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const int inf=2e9+9;

int num[maxn],go[maxn];

int main()
{
	int n,m,l;
	while(~scanf("%d%d%d",&n,&m,&l))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]),
			go[i]=num[i];
		}
		sort(go+1,go+1+n);
		for(int i=n+1;i<=n+l;i++)
			num[i]=num[i-n];
		int low=1,up=n,mid,ans=low;
		while(low<=up)
		{
			mid=low+(up-low)/2;
			//printf("**%d\n",go[mid]);
			int flag=0;
			for(int j=1;j<=l;j++)
			{
				int cnt=0;
				for(int i=j;i<=n+j-1;i++)
				{
					if(num[i]<go[mid])
					{
						cnt++;
						i+=l-1;
					}
				}
				if(cnt<=m)
				{
					flag=1;break;
				}
			}
			if(flag==1)
			{
				ans=max(ans,mid);
				low=mid+1;
			}
			else
				up=mid-1;
		}
		printf("%d\n",go[ans]);
	}
	return 0;
}

