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
const int maxn = 3e3 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;


int main()
{
	//std::ios::sync_with_stdio(false);

	int t;
	scanf("%d", &t);
	int flag = 0;
	while (t--)
	{
		if (flag != 0) puts("");
		flag = 1;
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			sum += x;
		}
		printf("%d\n", sum);
	}
	return 0;

}
