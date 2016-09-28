#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int maxn=2e5+9;

ll a[maxn],b[maxn];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<n;i++)
			b[i]=a[i]+a[i+1];
		b[n]=a[n];
		for(int i=1;i<=n;i++)
		{
			if(i==1) printf("%lld",b[i]);
			else printf(" %lld",b[i]);
		}
		printf("\n");
	}
	return 0;
}
