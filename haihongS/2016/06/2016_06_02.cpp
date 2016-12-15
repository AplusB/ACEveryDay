#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
const int maxn=109;
int n,m,k;

struct mat
{
	ll v[maxn][maxn];
}E,p;

mat mul(mat a,mat b);
mat quick_pow();


int main()
{
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
		{
			if(i==j) E.v[i][j]=1;
			else E.v[i][j]=0;
		}
	while(scanf("%d%d%d",&n,&m,&k) && n+m+k)
	{
		p=E;
		for(int i=0;i<k;i++)
		{
			char op[10];
			scanf("%s",op);
			int x,y;
			if(op[0]=='g')
			{
				scanf("%d",&x);
				x--;
				p.v[n][x]+=1;
			}
			else if(op[0]=='s')
			{
				scanf("%d%d",&x,&y);
				x--,y--;
				for(int j=0;j<=n;j++)
				{
					ll tmp=p.v[j][x];
					p.v[j][x]=p.v[j][y];
					p.v[j][y]=tmp;
				}
			}
			else
			{
				scanf("%d",&x);
				x--;
				for(int j=0;j<=n;j++)
					p.v[j][x]=0;
			}
		}
		mat ans=quick_pow();
		for(int i=0;i<n;i++)
		{
			if(i==0)
				printf("%lld",ans.v[n][i]);
			else printf(" %lld",ans.v[n][i]);
		}
		printf("\n");

	}
	return 0;
}

mat quick_pow()
{
	mat ans=E;
	while(m)
	{
		if(m&1)
			ans=mul(ans,p);
		p=mul(p,p);
		m>>=1;
	}
	return ans;
}

mat mul(mat a,mat b)
{
	mat c;
	memset(c.v,0,sizeof(c.v));
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(a.v[i][j]==0) continue;
			for(int kk=0;kk<=n;kk++)
			{
				c.v[i][kk]+=a.v[i][j]*b.v[j][kk];
			}
		}
	}
	return c;
}
