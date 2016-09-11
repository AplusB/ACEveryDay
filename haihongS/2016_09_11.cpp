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
const int maxn = 2e5 + 9;

char num[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		scanf("%s", num);
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++)
		{
			if (num[i] == '0') cnt1++;
			else cnt2++;
		}
		int ans = min(cnt1, cnt2);
		printf("%d\n", n - 2*ans);

	}
	return 0;
}
