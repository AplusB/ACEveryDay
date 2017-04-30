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

int a[maxn];

int main()
{
	int n, k;
	while (~scanf("%d%d", &n, &k))
	{
		int up = 1;
		for (int i = 1; i <= k; i++)
			up *= 2;
		if (up > n)
		{
			puts("-1");
			continue;
		}
		int pos = 0;
		for (int i = 2; i <= n; i++)
		{
			if (pos == k-1) break;
			if (n == 1 || n==0) break;
			while (n%i == 0 && pos<k-1)
			{
				a[pos++] = i;
				n /= i;
			}
		}
		if (pos == k - 1 && n > 1) a[pos++] = n;
		if (pos < k) puts("-1");
		else
		{
			for (int i = 0; i < pos; i++)
			{
				if (i != 0) printf(" ");
				printf("%d", a[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
