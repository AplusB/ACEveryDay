#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 9;

int a[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		int minn = 2000;
		for (int i = 2; i < n; i++)
		{
			int now = a[i];
			a[i] = a[i - 1];
			int maxx = 0;
			for (int j = 2; j <= n; j++)
			{
				int del = a[j] - a[j - 1];
				if (del > maxx) maxx = del;
			}
			minn = min(minn, maxx);
			a[i] = now;
		}
		printf("%d\n", minn);
	}
	return 0;
}
