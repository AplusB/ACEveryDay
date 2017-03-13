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
const int maxn = 2e5 + 9;
const ll inf = 1e9 + 9;

ll f[100];


int main()
{
	//std::ios::sync_with_stdio(false);
	f[0] = 0, f[1] = 1;
	for (int i = 2; i <= 50; i++)
		f[i] = f[i - 1] + f[i - 2];
	int n;
	while (~scanf("%d", &n) && n != -1)
	{
		printf("%lld\n", f[n]);

	}
	return 0;

}

