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
const int maxn = 2e5 + 9;
const ll inf = 1e9 + 9;

int a[maxn], b[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (n % 2 == 1)
		{
			for (int i = 1; i <= n; i++)
			{
				if (i % 2 == 0) b[i] = a[i];
				else
				{
					b[n - i + 1] = a[i];
				}
			}
		}
		else
		{
			int pos = n;
			for (int i = 1; i <= n / 2; i++)
			{
				if (i % 2 == 0) b[i] = a[i];
				else
				{
					b[pos] = a[i];
					pos -= 2;
				}
			}
			pos = 1;
			for (int i = n; i > n / 2; i--)
			{
				if ((n - i) % 2 == 1) b[i] = a[i];
				else
				{
					b[pos] = a[i];
					pos += 2;
				}
			}
		}
		
		for (int i = 1; i <= n; i++)
		{
			if (i != 1) printf(" ");
			printf("%d", b[i]);
		}
		printf("\n");
	}
	return 0;

}

