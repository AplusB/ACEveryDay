#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e5+60;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int a[maxn];

int main()
{
	int n,t;
	while(~scanf("%d%d",&n,&t))
	{
		for(int i=1;i<n;i++)
			scanf("%d",&a[i]);
		int now=1;
		while(now<t)
		{
			now+=a[now];
		}
		if(now==t)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
