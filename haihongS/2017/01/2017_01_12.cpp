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

using namespace std;
typedef long long ll;
const int maxn = 3e5 + 9;
const ll inf = 1e9 + 9;

int main()
{
	//std::ios::sync_with_stdio(false);
	int a1, b1, c1, a2, b2, c2;
	while (~scanf("%d.%d.%d", &a1, &b1, &c1))
	{
		scanf("%d.%d.%d", &a2, &b2, &c2);
		int a = a1 + a2, b = b1 + b2, c = c1 + c2;
		int add = 0;
		add = c / 29;
		c %= 29;
		b = b + add;
		add = b / 17;
		b %= 17;
		a += add;
		printf("%d.%d.%d\n", a, b, c);

	}

	return 0;
}
