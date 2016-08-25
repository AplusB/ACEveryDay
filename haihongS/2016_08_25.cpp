#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
const int maxn=2e4+9;
const int inf=2e9+9;

int p[200][200];

int V;
vector<int> G[maxn];
int match[maxn];
bool used[maxn];
int flag[200][200];

void add_edge(int u,int v);
bool dfs(int v);
int bi();

int main()
{
	//freopen("cc","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%d",&p[i][j]);
			}
		}
		//init
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
		}
		memset(flag,0,sizeof(flag));
		
		V=2*n;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(flag[min(i,j)][max(i,j)]==1) continue;
				if(i==j) continue;
				int ff=0;
				for(int k=0;k<m;k++)
				{
					if(p[i][k]<=p[j][k])
					{
						ff=1;break;
					}
				}
				if(ff==0)
				{
					add_edge(i,n+j);
					flag[min(i,j)][max(i,j)]=1;
				}
			}
		}
		printf("Case #%d: ",cas++);
		printf("%d\n",n-bi());
	}
	return 0;
}


int bi()
{
	int res=0;
	memset(match,-1,sizeof(match));
	for(int v=0;v<V;v++)
	{
		if(match[v]<0)
		{
			memset(used,0,sizeof(used));
			if(dfs(v))
				res++;
		}
	}
	return res;
}

bool dfs(int v)
{
	used[v]=true;
	int len=G[v].size();
	for(int i=0;i<len;i++)
	{
		int u=G[v][i];
		int w=match[u];
		if(w<0 || !used[w] && dfs(w))
		{
			match[v]=u;
			match[u]=v;
			return true;
		}
	}
	return false;
}

void add_edge(int u,int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}
