#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 5e2 + 9;
const ll inf = 1e9 + 9;

char a[maxn][maxn];


int main()
{
	//std::ios::sync_with_stdio(false);
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		for (int i = 0; i < n; i++)
			scanf("%s", a[i]);
		int uu, dd, ll, rr;
		uu = dd = ll = rr = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{ 
				if (a[i][j] != 'X') continue;
				if (uu == -1 || i < uu) uu = i;
				if (dd == -1 || i > dd) dd = i;
				if (ll == -1 || j < ll) ll = j;
				if (rr == -1 || j > rr) rr = j;
			}
		}
		int flag = 1;
		for (int i = uu; i <= dd; i++)
		{
			if (flag == 0) break;
			for (int j = ll; j <= rr; j++)
			{
				if(a[i][j]!='X')
				{
					flag = 0; break;
				}
			}
		}
		//printf("*%d %d %d %d\n", ll, rr, uu, dd);
		if (flag) puts("YES");
		else puts("NO");

	}
	return 0;

}

