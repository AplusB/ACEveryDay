#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const double inf=1e9;
const double eps=1e-12;

int t[maxn];

int main()
{
	int n,d;
	while(~scanf("%d%d",&n,&d))
	{
		int sum=0;
		for(int i=0;i<n;i++)
			scanf("%d",&t[i]),sum+=t[i];
		if(sum+(n-1)*10>d)
		{
			printf("-1\n");continue;
		}
		int ans=d-sum;
		ans=ans/5;
		printf("%d\n",ans);
	}
	return 0;
}

