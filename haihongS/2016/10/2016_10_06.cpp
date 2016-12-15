#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e6+10;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

map<int,int> b;
int a[maxn];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int cnt=0;
		b.clear();
		int kk=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[a[i]]++;
			if(a[i]>m) kk++;
		}
		int v=n/m;
		for(int i=1;i<=m;i++)
		{
			if(b[i]<v) cnt+=v-b[i];
		}
		if(kk>=cnt)
		{
			int now=cnt;
			for(int i=1;i<=n;i++)
			{
				if(now==0) break;
				if(a[i]>m)
				{
					a[i]=0;now--;
				}
			}

		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]>m) a[i]=0;
			}
			int now=cnt-kk;
			for(int j=1;j<=m;j++)
			{
				if(b[j]>v)
				{
					for(int i=1;i<=n;i++)
					{
						if(now==0) break;
						if(b[j]==v) break;
						if(a[i]==j)
						{
							a[i]=0;
							b[j]--;
							now--;
						}
					}
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(b[i]==v) break;
				if(b[i]>v) break;
				if(a[j]==0)
				{
					a[j]=i;
					b[i]++;
				}
			}
		}
		printf("%d %d\n",v,cnt);
		for(int i=1;i<=n;i++)
		{
			if(i!=1) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");

	}
	return 0;
}
