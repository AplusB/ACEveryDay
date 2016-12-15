#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const ll mod=1e4+7;

ll n;

struct mat
{
	ll v[3][3];
}E,fir;


mat mul(mat a,mat b);
mat pow(mat x,ll n);

int main()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			E.v[i][j]=fir.v[i][j]=0;
		}
	E.v[0][0]=E.v[1][1]=E.v[2][2]=1;
	fir.v[0][0]=2LL,fir.v[0][1]=1LL,fir.v[1][1]=fir.v[1][2]=fir.v[1][0]=2LL,fir.v[2][1]=1LL,fir.v[2][2]=2LL;
	fir.v[0][2]=fir.v[2][0]=0;

	int t;
	scanf("%d",&t);
	while(t--)	
	{
		scanf("%lld",&n);
		mat ans=pow(fir,n);
		printf("%lld\n",ans.v[0][0]);
	}
	return 0;
}


mat pow(mat x,ll n)
{
	mat ans=E;
	while(n)
	{
		if(n&1)
		{
			ans=mul(ans,x);
		}
		x=mul(x,x);
		n>>=1;
	}
	return ans;
}

mat mul(mat a,mat b)
{
	mat c;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			ll tmp=0;
			for(int k=0;k<3;k++)
			{
				tmp+=a.v[i][k]*b.v[k][j];
				tmp%=mod;
			}
			c.v[i][j]=tmp;
		}
	}
	return c;
}
