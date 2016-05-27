#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int cmp(const void *a, const void*b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int n;
	while (cin >> n)
	{
		__int64 *w = new __int64[n + 1];
		for (int p = 1; p <= n; p++)
			scanf("%I64d", &w[p]);
		qsort(w, n + 1, sizeof(__int64), cmp);
		__int64 mincost = 0;
		for (int i = 1; i <= n - 1; i++)
		{
			__int64 sum = w[i] + w[i + 1];
			mincost += sum;
			for (int j = i + 2; j <= n; j++)
			{
				if (sum>w[j])
				{
					w[j - 1] = w[j];
					if (j == n)
					{
						w[j] = sum;
						break;
					}
				}
				else
				{
					w[j - 1] = sum;
					break;
				}
			}
		}
		printf("%I64d\n", mincost);
	}
}
