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
const int maxn = 4e2 + 9;
const ll inf = 1e9 + 9;

int gcd(int x, int y);

int main()
{
	//std::ios::sync_with_stdio(false);
	int n, m, z;
	while (~scanf("%d%d%d", &n, &m, &z))
	{
		int ans = 0;
		int lcm = n*m / gcd(n, m);
		ans = z / lcm;
		printf("%d\n", ans);
	}
	return 0;

}

int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x%y);
}
