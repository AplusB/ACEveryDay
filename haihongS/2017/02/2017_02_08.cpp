#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int a[maxn],b[maxn],del[maxn],d2[maxn];

int main()
{
	int n,l;
	while(~scanf("%d%d",&n,&l))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		del[1]=a[1]-0+l-a[n];
		for(int i=2;i<=n;i++)
			del[i]=a[i]-a[i-1];
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		d2[1]=b[1]-0+l-b[n];
		for(int i=2;i<=n;i++)
			d2[i]=b[i]-b[i-1];
		for(int i=n+1;i<=2*n;i++)
			del[i]=del[i-n];
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			int ok=1;
			for(int j=i;j<n+i;j++)
			{
				if(del[j]!=d2[j-i+1])
				{
					ok=0;break;
				}
			}
			if(ok)
			{
				flag=1;break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}
