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
#include <functional>

using namespace std;
typedef long long ll;
const int maxn = 2e6 + 9;
const ll inf = 1e9 + 9;

int now[maxn];

int judge(int x);

int main()
{
	//std::ios::sync_with_stdio(false);
	memset(now, 0, sizeof(now));
	for (int i = 0; i < maxn; i++)
		now[i] = judge(i);
	int a, b;
	while (scanf("%d %d", &a, &b) && a + b)
	{
		int cnt = 0;
		for (int i = a; i <= b; i++)
		{
			cnt += now[i];
		}
		printf("%d\n", cnt);
	}
	return 0;

}

int judge(int x)
{
	int ok[10] = { 0 };
	int pos = 0;
	while (x)
	{
		ok[pos++] = x % 10;
		x /= 10;
	}
	for (int i = 0; i < pos; i++)
	{
		if (ok[i] == 4) return 0;
	}
	for (int i = 0; i < pos - 1; i++)
	{
		if (ok[i] == 2 && ok[i + 1] == 6) return 0;
	}
	return 1;
}
