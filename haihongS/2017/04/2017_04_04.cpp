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
#include <set>
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 3e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);


	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		int cnt = 0;
		for (int i = 2; i < n; i++)
		{
			if (a[1] < a[i] && a[i] < a[n])
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;

}
