#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 100005;

vector<int> g[MAXN];
int d[MAXN],b[MAXN],a[MAXN],mark[MAXN];
int n,m,flag,cur;

void dfs(int x,int f,int pre)
{
	if(mark[x])pre = x;
	if(a[x] != pre && pre != 0)flag = 1;
	int i;
	for(i = 0;i < g[x].size();i++)
	{
		int v = g[x][i];
		dfs(v,x,pre);
	}
	if(mark[x])b[cur++] = x;
}

int main()
{
	scanf("%d %d",&n,&m);
	
	flag = cur = 0;
	int i,u,v;
	for(i = 0;i < m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		d[v]++;
	}
	
	for(i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		mark[a[i]] = 1;
	}
	
	for(i = 1;i <= n;i++)
	{
		if(d[i])continue;
		dfs(i,0,0);
	}
	
	if(flag)cout << -1 << endl;
	else{
		cout << cur << endl;
		for(i = 0;i < cur;i++)
		{
			cout << b[i] << endl;
		}
	}
	return 0;
}
