#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int x[5],y[5];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		if(n==1)
			printf("-1\n");
		else if(n==2)
		{
			if(x[0]==x[1] || y[0]==y[1])
				printf("-1\n");
			else
			{
				int ans=0;
				ans=abs(x[0]-x[1])*abs(y[0]-y[1]);
				printf("%d\n",ans);
			}
		}
		else
		{
			sort(x,x+n);
			sort(y,y+n);
			int ans=abs(x[0]-x[n-1])*abs(y[0]-y[n-1]);
			printf("%d\n",ans);
		}
	}
	return 0;
}
