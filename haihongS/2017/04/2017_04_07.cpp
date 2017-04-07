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
const int maxn = 2e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[10];


int main()
{
	//std::ios::sync_with_stdio(false);

	/*
	a[0] = 0, a[1] = 1, a[2] = 2;
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 0)
				swap(a[0], a[1]);
			else
				swap(a[1], a[2]);
			printf("%d: %d %d %d\n", i, a[0], a[1], a[2]);
		}
	}
	*/

	int n, x;
	while (~scanf("%d%d", &n, &x))
	{
		n %= 6;
		a[0] = 0, a[1] = 1, a[2] = 2;
		for (int i = 1; i <= n; i++)
		{
			if (i % 2 == 1) swap(a[0], a[1]);
			else swap(a[1], a[2]);
		}
		printf("%d\n", a[x]);
	}

	
	return 0;
}


