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

const int maxn = 2e5 + 9;


int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x == 1) a++;
			else if (x == 2) b++;
			else if (x == 3) a++, b++;
			else a--, b--;
		}
		if (a == b) puts("Draw");
		else if (a > b) puts("Kobayashi");
		else puts("Tohru");
	}
	return 0;
}

