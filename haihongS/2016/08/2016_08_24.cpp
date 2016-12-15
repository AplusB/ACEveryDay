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

char mapp[100][100];

int V;
vector<int> G[maxn];
int match[maxn];
bool used[maxn];
int dx[4]={-1,1,-1,1},dy[4]={0,0,-1,-1};

void add_edge(int u,int v);
bool dfs(int v);
int bi();

int main()
{
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)
			scanf("%s",mapp[i]);
		for(int i=0;i<maxn;i++)
			G[i].clear();
		int cnt=0;
		V=n*m;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mapp[j][i]=='x') continue;
				cnt++;
				for(int k=0;k<4;k++)
				{
					int nx=i+dx[k],ny=j+dy[k];
					if(0<=nx && nx<n && 0<=ny && ny<m && mapp[ny][nx]=='.')
						add_edge(j*n+i,ny*n+nx);
				}
			}
		}
		printf("Case #%d: ",cas++);
		printf("%d\n",cnt-bi());
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
	for(int i=0;i<G[v].size();i++)
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
