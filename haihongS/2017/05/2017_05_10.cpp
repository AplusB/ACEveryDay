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

int a[100], b[100];



int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		int pos = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[pos])
			{
				ans++;
				pos++;
			}
		}
		printf("%d\n", n - ans);

	}
	return 0;
}

