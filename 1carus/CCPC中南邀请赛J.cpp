#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <vector>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;

struct node{
	int val,index;
	const bool operator < (node old) const
	{
		return val > old.val;
	}
}p[MAXN];

int n;
vector<int> g[MAXN];
int sum[MAXN];


int main()
{
	while(scanf("%d",&n) == 1)
	{
		memset(sum,0,sizeof(sum));
		
		int i;
		
		for(i = 0;i <= n;i++)g[i].clear();
		
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&p[i].val);
			p[i].index = i;
		}
		
		int x,y;
		for(i = 0;i < n - 1;i++)
		{
			scanf("%d %d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
			sum[x] += p[y].val;
			sum[y] += p[x].val;
		}
		
		sort(p + 1,p + 1 + n);
		
		long long ans = 0;
		int j;
		for(i = 1;i <= n;i++)
		{
			ans += sum[p[i].index];
			for(j = 0;j < g[p[i].index].size();j++)
			{
				int temp = g[p[i].index][j];
				sum[temp] -= p[i].val;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
}
