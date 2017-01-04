#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+9;
const int inf=2e9+9;

struct II
{
	int now,nx;
	char data[6];
}a[maxn];

int flag[maxn],aha[maxn];


int main()
{
	int n,p1,p2;
	while(~scanf("%d %d %d",&p1,&p2,&n))
	{
		for(int i=0;i<maxn;i++)
		{
			flag[i]=0;
			aha[i]=-1;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%s%d",&a[i].now,a[i].data,&a[i].nx);
			aha[a[i].now]=a[i].nx;
		}
		int fir=p1;
		while(fir!=-1)
		{
			flag[fir]++;
			fir=aha[fir];
		}
		fir=p2;
		while(fir!=-1)
		{
			if(flag[fir]==1)
			{
				break;
			}
			fir=aha[fir];
		}
		if(fir==-1) printf("-1\n");
		else printf("%05d\n",fir);
	}
	return 0;
}



