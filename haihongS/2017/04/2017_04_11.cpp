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
const int maxn = 2e6 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);

	int n;
	while (~scanf("%d", &n))
	{
		memset(a, 0, sizeof(a));
		a[0] = 1;
		int len = 1;
		for (int i = 2; i <= n; i++)
		{
			int _carry = 0;
			for (int j = 0; j < len; j++)
			{
				a[j] = i*a[j] + _carry;
				_carry = a[j] / 10;
				a[j] %= 10;
			}
			while (_carry != 0)
			{
				a[len++] = _carry % 10;
				_carry /= 10;
			}
		}
		for (int i = len - 1; i >= 0; i--)
			printf("%d", a[i]);
		puts("");
	}
	
	return 0;
}


