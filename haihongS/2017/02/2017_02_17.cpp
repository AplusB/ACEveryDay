#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=20+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

struct mat
{
	double v[maxn][maxn];
};

double a[maxn],ans[maxn];
int n;

mat mul(mat x,mat y);
mat quick_pow(mat m,int x);


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		mat base;
		memset(base.v,0,sizeof(base.v));
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			if(k==0) 
			{
				base.v[i][i]=1.0;
				continue;
			}
			for(int j=0;j<k;j++)
			{
				int tmp;
				scanf("%d",&tmp);
				base.v[i][tmp]=1.0/k;
			}
		}
		int m;
		scanf("%d",&m);
		base=quick_pow(base,m);
		for(int i=1;i<=n;i++)
		{
			ans[i]=0;
			for(int j=1;j<=n;j++)
				ans[i]+=a[j]*base.v[j][i];
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=1) printf(" ");
			printf("%.2lf",ans[i]);
		}
		printf("\n");
		
	}
	return 0;
}

mat quick_pow(mat m,int x)
{
	mat ans;
	memset(ans.v,0,sizeof(ans.v));
	for(int i=1;i<=n;i++) ans.v[i][i]=1.0;

	while(x)
	{
		if(x&1) ans=mul(ans,m);
		m=mul(m,m);
		x>>=1;
	}
	return ans;
}

mat mul(mat x,mat y)
{
	mat ans;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans.v[i][j]=0;
			for(int k=1;k<=n;k++)
			{
				ans.v[i][j]+=x.v[i][k]*y.v[k][j];
			}
		}
	}
	return ans;
}
