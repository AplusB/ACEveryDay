#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn=10;

int n,m;

struct mat
{
	int v[maxn][maxn];
}E,p;

int f[maxn];

mat mul(mat a,mat b);
mat quick_pow(mat d,int x);

int main()
{

	f[0]=1,f[1]=1,f[2]=5,f[3]=11,f[4]=36,f[5]=95;
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
		{
			if(i==j) E.v[i][j]=1;
			else E.v[i][j]=0;
			p.v[i][j]=0;
		}
	p.v[0][0]=1,p.v[0][1]=5,p.v[0][2]=1,p.v[0][3]=-1;
	for(int i=1;i<4;i++) p.v[i][i-1]=1;
	
	while(scanf("%d%d",&n,&m) && n+m)
	{
		if(n<=4)
		{
			printf("%d\n",f[n]%m);continue;
		}
		mat tt=quick_pow(p,n-3);
		int ans=0;
		ans=(tt.v[0][0]%m+m)%m;
		printf("%d\n",ans);
	}

	return 0;
}

mat quick_pow(mat d,int x)
{
	mat ans;
	for(int i=0;i<4;i++)
	{
		ans.v[i][0]=f[3-i];
	}
	while(x)
	{
		if(x&1)
			ans=mul(d,ans);
		d=mul(d,d);
		x>>=1;
	}
	return ans;
}

mat mul(mat a,mat b)
{
	mat c;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int tmp=0;
			for(int k=0;k<4;k++)
			{
				tmp+=(a.v[i][k]%m)*(b.v[k][j]%m);
				tmp%=m;
			}
			c.v[i][j]=tmp;
		}
	}
	return c;
}
