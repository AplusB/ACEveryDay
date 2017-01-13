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
	int n;
	while (~scanf("%d", &n))
	{
		int minn = inf, maxx = 0;
		for (int i = 1; i < 8; i++)
		{
			int now = 0;
			now += n / 7 * 2;
			int tmp = n % 7;
			for (int j = i; j < i + tmp; j++)
				if (j%8 == 6 || j%8 == 7) now++;
			minn = min(minn, now);
			maxx = max(maxx, now);
		}
		printf("%d %d\n", minn, maxx);
	}

	return 0;
}
