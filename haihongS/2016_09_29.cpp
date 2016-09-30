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

char a[maxn];

int main()
{
	while (~scanf("%s", a))
	{
		int len = strlen(a);
		if(len%2==1)
		{
			printf("-1\n");
			continue;
		}
		int l, r, u, d;
		l = r = u = d = 0;
		for (int i = 0; i < len; i++)
		{
			if (a[i] == 'L') l++;
			else if (a[i] == 'R') r++;
			else if (a[i] == 'U') u++;
			else if (a[i] == 'D') d++;
		}
		int d1 = max(l, r) - min(l, r);
		int d2 = max(u, d) - min(u, d);
		printf("%d\n", (d1 + d2) / 2);

	}
	
	return 0;
}
