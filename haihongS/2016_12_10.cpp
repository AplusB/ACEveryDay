#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=5e2+60;
const double inf=1e9;
const double eps=1e-12;

vector<int> G[maxn];
int ans[maxn],maxx;

void dfs(int v,int dep);

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		memset(ans,0,sizeof(ans));

		for(int i=0;i<m;i++)
		{
			int f,s;
			scanf("%d %d",&f,&s);
			for(int i=0;i<s;i++)
			{
				int v;
				scanf("%d",&v);
				G[f].push_back(v);
			}
		}
		maxx=0;
		dfs(1,0);
		for(int i=0;i<=maxx;i++)
		{
			if(i!=0) printf(" ");
			printf("%d",ans[i]);
		}
		printf("\n");

	}
	return 0;
}

void dfs(int v,int dep)
{
	int len=G[v].size();
	maxx=max(maxx,dep);
	if(len==0)
	{
		ans[dep]++;
		return ;
	}
	for(int i=0;i<len;i++)
		dfs(G[v][i],dep+1);
	return ;
}
