#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 9;
const int inf = 1e9 + 9;

string num[20];
int n;
int dp[1 << 17][20], cost[20][20];
int use[20];
string ans;

int cmp(const string &x, const string &y);
int init();
int dfs(int cnt, int state, string s, int loca, int len);

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t;
	scanf("%d", &t);
	int cass = 1;
	while (t--)
	{
		scanf("%d", &n);
		//for (int i = 0; i<n; i++) cin >> num[i];
		int len = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> num[len];
			for (int j = 0; j < len;j++)
			{ 
				if(num[j].find(num[len])<num[j].length())
				{
					len--; break;
				}
				if (num[len].find(num[j]) < num[len].length())
				{
					num[j] = num[len];
					len--; break;
				}
			}
			len++;
		}
		n = len;
		printf("Scenario #%d:\n", cass++);

		sort(num, num + len, cmp);
		/*
		int len = unique(num, num + n) - num;
		*/

		for (int i = 0; i<(1 << len); i++)
		{
			for (int j = 0; j<len; j++)
				dp[i][j] = inf;
		}
		for (int i = 0; i<len; i++)
		{
			dp[1 << i][i] = num[i].length();
		}
		init();

		for (int i = 0; i<(1 << len); i++)
		{
			for (int j = 0; j<len; j++)
			{
				if (((1 << j)&i) == 0) continue;
				for (int u = 0; u<len; u++)
				{
					if ((i >> u) & 1) continue;
					if (dp[i][j] == inf) continue;
					int tmp = num[u].length();
					//dp[i | (1 << u)][j] = min(dp[i | (1 << u)][j], dp[i][j] + tmp + cost[j][u]);
					dp[i | (1 << u)][u] = min(dp[i | (1 << u)][u], dp[i][j] + tmp + cost[u][j]);
				}
			}
		}
		int loca = 0, minn = dp[(1 << len) - 1][0];
		for (int i = 1; i<len; i++)
		{
			if (dp[(1 << len) - 1][i]<minn)
			{
				minn = dp[(1 << len) - 1][i];
				loca = i;
			}
		}
		ans="";
		memset(use, 0, sizeof(use));
		use[loca] = 1;
		dfs(1, (1 << len) - 1, num[loca], loca, len);
		cout << ans << "\n\n";

	}
	return 0;
}

int dfs(int cnt, int state, string s, int loca, int len)
{
	if (cnt == len)
	{
		if (ans == "" || s<ans)
			ans = s;
		return 0;
	}
	string mm = "";
	int id = -1;
	for (int i = 0; i<len; i++)
	{
		if (use[i] == 1) continue;
		int tmp = num[loca].length();
		//if (dp[state][loca] != dp[state & (~(1 << loca))][i] + tmp + cost[loca][i]) continue;
		if (dp[state][loca] != dp[state ^ (1 << loca)][i] + tmp + cost[loca][i]) continue;
		string now = s;
		int uu = num[i].length();
		for (int j = -cost[loca][i]; j<uu; j++) 
			now = now + num[i][j];
		if (id == -1 || now<mm)
		{
			id = i; mm = now;
		}
	}
	use[id] = 1;
	dfs(cnt + 1, state ^ (1 << loca), mm, id, len);
	return 0;
}

int init()
{
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			// i>j
			int up = min(num[i].length(), num[j].length());
			int len = num[i].length();
			int tmp = 0;
			for (int k = 0; k<=up; k++)
			{
				int ff = 1;
				for (int s = 0; s<k; s++)
				{
					if (num[i][len - k + s] != num[j][s])
					{
						ff = 0; break;
					}
				}
				if (ff)
				{
					tmp = max(tmp, k);
				}
			}
			cost[i][j] = -tmp;
		}
	}
	return 0;
}

int cmp(const string &x, const string &y)
{
	return x<y;
}
