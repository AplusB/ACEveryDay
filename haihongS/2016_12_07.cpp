#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e3+60;
const double inf=1e9;
const double eps=1e-12;


int a[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		printf("%d\n",n);
		for(int i=0;i<n;i++)
		{
			int v=i;
			for(int j=i+1;j<n;j++)
			{
				if(a[j]<a[v]) v=j;
			}
			swap(a[i],a[v]);
			printf("%d %d\n",i,v);
		}
	}
	return 0;
}
