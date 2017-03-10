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


int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n))
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (n%i == 0) cnt++;
		}
		printf("%d\n", cnt % 2);
	}
	return 0;

}

