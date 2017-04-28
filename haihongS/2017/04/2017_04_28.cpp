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

int a[maxn];

int main()
{
	int ok = 0;
	while (~scanf("%d", &a[0]))
	{
		for (int i = 1; i < 4; i++)
			scanf("%d", &a[i]);
		if (a[0] == a[1] && a[1] == a[2] && a[3] == a[4] && a[4] == 0)
			break;
		if (ok == 1) puts("");
		ok = 1;
		sort(a, a + 4);

		int flag = 0, last = -1;
		if (a[0] != 0)
		{
			for (int i = 0; i < 4; i++)
				printf("%d", a[i]);
			flag = 1;
			last = a[0];
		}	
		while (next_permutation(a, a + 4))
		{
			if (a[0] == 0) continue;
			if (last!=-1 && a[0] != last)
			{
				puts("");
				last = a[0];
				flag = 0;
			}
			last = a[0];
			if (flag == 1) printf(" ");
			flag = 1;
			for (int i = 0; i < 4; i++)
				printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}
