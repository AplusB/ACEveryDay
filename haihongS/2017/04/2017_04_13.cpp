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
const int maxn = 2e3 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn], b[maxn], f1[10], f2[10], s[10];


int main()
{
	//std::ios::sync_with_stdio(false);

	int n;
	while (~scanf("%d", &n))
	{
		memset(f1, 0, sizeof(f1));
		memset(f2, 0, sizeof(f2));
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			f1[a[i]]++;
			s[a[i]]++;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
			f2[b[i]]++;
			s[b[i]]++;
		}

		int flag = 1, d1 = 0, d2 = 0;
		for (int i = 1; i <= 5; i++)
		{
			if (s[i] % 2 == 1)
			{
				flag = 0; break;
			}
			d1 += max(0, f1[i] - s[i] / 2);
			d2 += max(0, f2[i] - s[i] / 2);
		}
		if (d1 != d2) flag = 0;
		if (flag == 0)
		{
			puts("-1");
			continue;
		}
		printf("%d\n", d1);

		
		

	}
	
	return 0;
}


