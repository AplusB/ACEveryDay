#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

double dp[maxn],aa[maxn],bb[maxn];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k1,k2,k3,a,b,c;
		scanf("%d%d%d%d%d%d%d",&n,&k1,&k2,&k3,&a,&b,&c);
		for(int i=0;i<maxn;i++)
		{
			dp[i]=aa[i]=bb[i]=0;
		}
		double p0=1.0/(1.0*k1*k2*k3);
		for(int i=n;i>=0;i--)
		{
			for(int j1=1;j1<=k1;j1++)
				for(int j2=1;j2<=k2;j2++)
					for(int j3=1;j3<=k3;j3++)
						if(j1!=a || j2!=b || j3!=c)
							aa[i]+=p0*aa[i+j1+j2+j3],bb[i]+=p0*bb[i+j1+j2+j3];
			aa[i]+=p0;
			bb[i]+=1.0;
		}
		printf("%.20lf\n",1.0*bb[0]/(1-aa[0]));
	}
	return 0;
}
