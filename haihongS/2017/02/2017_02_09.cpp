#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=100+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

int des,pri;
int n,m;

struct mat
{
	ll v[maxn][maxn];
};

mat mul(mat a,mat b);
mat quick_pow(mat x,int t);

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mat tmp,now;
		for(int i=0;i<maxn;i++)
		{
			for(int j=0;j<maxn;j++)
			{
				tmp.v[i][j]=now.v[i][j]=0;
			}
		}
		scanf("%d%d",&n,&m);
		des=n*m-1,pri=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				char mm[200];
				scanf("%s",mm);
				int x[10],y[10];
				sscanf(mm,"((%d,%d),(%d,%d),(%d,%d),(%d,%d))",
				&x[0],&y[0],&x[1],&y[1],&x[2],&y[2],&x[3],&y[3]);
				for(int k=0;k<4;k++)
				{
					x[k]--,y[k]--;
					int u=i*m+j;
					int v=x[k]*m+y[k];
					if(u!=des && v!=des)
						now.v[u][v]=1;
					tmp.v[u][v]=1;
				}
			}
		}
		int q;
		scanf("%d",&q);
		while(q--)
		{
			int p;
			scanf("%d",&p);
			if(p==0)
			{
				if(m==1 && n==1) printf("True\n");
				else printf("False\n");
				continue;
			}
			mat go;
			go=quick_pow(now,p-1);
			go=mul(go,tmp);
			int flag=go.v[pri][des];
			if(flag==0) puts("False");
			else
			{
				int cnt=0;
				for(int i=pri;i<des;i++)
				{
					if(go.v[pri][i]>0)
					{
						cnt++;
					}
				}
				if(cnt==0) puts("True");
				else puts("Maybe");
			}
		}
		printf("\n");
	}
	return 0;
}

mat quick_pow(mat x,int t)
{
	mat ans;
	memset(ans.v,0,sizeof(ans.v));
	for(int i=pri;i<=des;i++)
		ans.v[i][i]=1;
	while(t>0)
	{
		if(t&1) ans=mul(ans,x);
		x=mul(x,x);
		t>>=1;
	}
	return ans;
}

mat mul(mat a,mat b)
{
	mat ans;
	for(int i=pri;i<=des;i++)
	{
		for(int j=pri;j<=des;j++)
		{
			ans.v[i][j]=0;
			for(int k=pri;k<=des;k++)
			{
				ans.v[i][j]+=a.v[i][k]*b.v[k][j];
			}
			if(ans.v[i][j]>0) ans.v[i][j]=1;
		}
	}
	return ans;
}
