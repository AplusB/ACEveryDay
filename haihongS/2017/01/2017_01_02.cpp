#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2000000+60;
const ll inf=2e9+9;

int a[maxn],b[maxn],c[maxn];

int main()
{
	int x,y;
	while(~scanf("%d",&x))
	{
		for(int i=0;i<x;i++)
			scanf("%d",&a[i]);
		scanf("%d",&y);
		for(int i=0;i<y;i++)
			scanf("%d",&b[i]);
		int pos=0;
		for(int i=0;i<x;i++)
			c[pos++]=a[i];
		for(int j=0;j<y;j++)
			c[pos++]=b[j];
		sort(c,c+pos);
		pos=unique(c,c+pos)-c;
		printf("%d\n",c[(pos-1)/2]);
	}
	return 0;
}
