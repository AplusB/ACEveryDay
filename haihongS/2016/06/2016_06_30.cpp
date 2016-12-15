#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=2e6+9;
const int inf=2e9+5;
typedef long long ll;

int flag[maxn];
int mark[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<maxn;i++)
		{
			flag[i]=0;
			mark[i]=inf;
		}
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			flag[x]++;
			mark[x]=i;
		}
		int ans=0;
		for(int i=1;i<maxn;i++)
		{
			if(flag[i]==flag[ans])
			{
				if(mark[i]<mark[ans])
					ans=i;
			}
			else if(flag[i]>flag[ans])
				ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}

