#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
const int maxn=2e5+9;
const ll inf=2e14+9;

ll x[5],y[5],z[5];
ll v[5];

ll cal(ll dx,ll dy,ll dz);

int main()
{
	while(~scanf("%lld%lld%lld",&x[0],&y[0],&z[0]))
	{
		scanf("%lld%lld%lld",&x[1],&y[1],&z[1]);
		scanf("%lld%lld%lld",&x[2],&y[2],&z[2]);
		int flag=1;
		if(!(x[1]<=x[0] && x[0]<=x[2])) flag=0;
		if(!(y[1]<=y[0] && y[0]<=y[2])) flag=0;
		if(!(z[1]<=z[0] && z[0]<=z[2])) flag=0;
		if(flag==1)
		{
			printf("0\n");continue;
		}
		ll ans=inf;
		for(int i=1;i<=2;i++)
		{
			for(int j=1;j<=2;j++)
			{
				for(int k=1;k<=2;k++)
				{
					ll nx=x[i],ny=y[j],nz=z[k];
					ans=min(ans,cal(nx-x[0],ny-y[0],nz-z[0]));
				}
			}
		}
		if(x[1]<=x[0] && x[0]<=x[2])
		{
			if(y[1]<=y[0] && y[0]<=y[2])
			{
				for(int i=1;i<=2;i++)
					ans=min(ans,cal(0,0,z[0]-z[i]));
			}
		}
		if(x[1]<=x[0] && x[0]<=x[2])
		{
			if(z[1]<=z[0] && z[0]<=z[2])
			{
				for(int i=1;i<=2;i++)
					ans=min(ans,cal(0,y[0]-y[i],0));
			}
		}
		if(y[1]<=y[0] && y[0]<=y[2])
		{
			if(z[1]<=z[0] && z[0]<=z[2])
			{
				for(int i=1;i<=2;i++)
					ans=min(ans,cal(x[0]-x[i],0,0));
			}
		}
		if(x[1]<=x[0] && x[0]<=x[2])
		{
			for(int i=1;i<=2;i++)
			{
				for(int j=1;j<=2;j++)
				{
					ll ny=y[i],nz=z[j];
					ans=min(ans,cal(0,ny-y[0],nz-z[0]));
				}
			}
		}
		if(y[1]<=y[0] && y[0]<=y[2])
		{
			for(int i=1;i<=2;i++)
			{
				for(int j=1;j<=2;j++)
				{
					ll nx=x[i],nz=z[j];
					ans=min(ans,cal(nx-x[0],0,nz-z[0]));
				}
			}
		}
		if(z[1]<=z[0] && z[0]<=z[2])
		{
			for(int i=1;i<=2;i++)
			{
				for(int j=1;j<=2;j++)
				{
					ll nx=x[i],ny=y[j];
					ans=min(ans,cal(nx-x[0],ny-y[0],0));
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

ll cal(ll dx,ll dy,ll dz)
{
	return dx*dx+dy*dy+dz*dz;
}
