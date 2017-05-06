#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 9;
const ll inf = 1e15;

map<string, int> aha;
vector<int> a[110];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < 110; i++) a[i].clear();
		aha.clear();
		int idd = 1;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			string now;
			int v;
			cin >> now >> v;
			if (aha[now] == 0) aha[now] = idd++;
			int tmp = aha[now];
			a[tmp].push_back(v);
		}
		for (int i = 1; i < idd; i++)
		{
			sort(a[i].begin(), a[i].end());
		}
		int ans = 0;
		for (int i = 1; i < idd; i++)
		{
			int len = a[i].size();
			for (int j = len - 1; j >= 0 && j >= len - 2; j--)
			{
				ans += a[i][j];
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
