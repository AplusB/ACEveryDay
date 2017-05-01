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

string x, y;

int main()
{
	int a, b, k;
	while (~scanf("%d%d%d", &a, &b, &k) && a + b)
	{
		x = y = "";
		int tmp = a;
		while (tmp)
		{
			x += '0' + tmp % 10;
			tmp /= 10;
		}
		tmp = b;
		while (tmp)
		{
			y += '0' + tmp % 10;
			tmp /= 10;
		}
		for (int i = 0; i < 10; i++)
		{
			x += '0';
			y += '0';
		}
		int flag = 1;
		for (int i = 0; i < k; i++)
		{
			if (x[i] != y[i])
			{
				flag = 0; break;
			}
		}
		if (flag) puts("-1");
		else printf("%d\n", a + b);
	}
	return 0;
}
