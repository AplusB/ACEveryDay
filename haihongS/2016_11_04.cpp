#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e7+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-6;

int main()
{
	int x,y;
	while(~scanf("%d%d",&x,&y))
	{
		if(x>y)
		{
			printf("-1\n");continue; 
		}
		double nx,ny;
		nx=1.0*x,ny=1.0*y;
		double go=1.0*(ny+1-eps)/nx;
		int ans=x-1;
		double all=1;
		for(int i=1;i<=x;i++)
		{
			double now=1.0*go*i;
			int del=max(0,(int)(now-all));
			ans+=del;
			all+=1.0*del;	
			all+=1.0*all/i;
			
		}
		printf("%d\n",ans);		
	}
	return 0;
}
