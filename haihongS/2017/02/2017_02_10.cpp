#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int a[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int sum=0,ok=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
			if(a[i]!=0) ok=1;
		}
		if(sum!=0)
		{
			puts("YES");
			printf("1\n1 %d\n",n);
		}
		else if(ok==0) puts("NO");
		else
		{
			int now=0;
			for(int i=1;i<=n;i++)
			{
				now+=a[i];
				if(now!=0 && sum-now!=0)
				{
					now=i;break;
				}
			}
			puts("YES");
			printf("2\n1 %d\n%d %d\n",now,now+1,n);
		}

	}
	return 0;
}
