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

int day[20] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

int judge(int x);

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int y, m, d;
		scanf("%d-%d-%d", &y, &m, &d);
		if (m == 2 && d==29)
		{
			if (judge(y + 18) == 0)
			{
				puts("-1");
				continue;
			}
		}
		int ans = 0;
		for (int i = y + 1; i < y + 18; i++)
		{
			if (judge(i)) ans += 366;
			else ans += 365;
		}
		
		ans += day[m] - d;
		if (m == 2 && judge(y) == 1)
			ans += 1;
		for (int i = m + 1; i <= 12; i++)
		{
			ans += day[i];
			if (i == 2 && judge(y) == 1) ans += 1;
		}
		y += 18;
		for (int i = 1; i < m; i++)
		{
			ans += day[i];
			if (i == 2 && judge(y) == 1) ans += 1;
		}
		ans += d;
		printf("%d\n", ans);
		
	}
	return 0;
}

int judge(int x)
{
	if (x % 100 == 0)
	{
		if (x % 400 == 0) return 1;
		else return 0;
	}
	else
	{
		if (x % 4 == 0) return 1;
		return 0;
	}
}
