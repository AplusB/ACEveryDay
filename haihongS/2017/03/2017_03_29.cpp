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
const int maxn = 3e4 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;

char a[maxn], b[maxn];
int ans[maxn];

void rev(char *x);

int main()
{
	//std::ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--)
	{
		if (cas != 1) puts("");
		scanf("%s", a);
		scanf("%s", b);
		printf("Case %d:\n", cas++);
		printf("%s + %s = ", a, b);

		int alen = strlen(a), blen = strlen(b);
		if (blen > alen)
		{
			swap(a, b);
			swap(alen, blen);
		}

		rev(a);
		rev(b);
		
		int op = 0;
		for (int i = 0; i < blen; i++)
		{
			int x1 = a[i] - '0', x2 = b[i] - '0';
			int sum = x1 + x2 + op;
			ans[i] = sum % 10;
			op = sum / 10;
		}
		for (int i = blen; i < alen; i++)
		{
			int x = a[i] - '0';
			int sum = x + op;
			ans[i] = sum % 10;
			op = sum / 10;
		}
		if (op != 0)
		{
			ans[alen] = op;
			op = -1;
		}
		for (int i = (op == -1 ? alen : alen - 1); i >= 0; i--)
			printf("%d", ans[i]);
		puts("");

	}

	
	return 0;

}

void rev(char *x)
{
	int len = strlen(x);
	for (int i = 0; i < len / 2; i++)
	{
		char tmp = x[i];
		x[i] = x[len - i - 1];
		x[len - i - 1] = tmp;
	}

}
