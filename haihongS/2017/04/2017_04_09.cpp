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

ll a[200][200], dp[200][200];


int main()
{
	//std::ios::sync_with_stdio(false);

	int n;
	while (~scanf("%d", &n) && n)
	{
		int s1 = 0, s2 = 0, s3 = 0;
		int now = n;
		while (now)
		{
			s1 += now % 10;
			now /= 10;
		}

		now = n;
		while (now)
		{
			s2 += now % 12;
			now /= 12;
		}

		now = n;
		while (now)
		{
			s3 += now % 16;
			now /= 16;
		}
		if (s1 == s2 && s2 == s3)
			printf("%d is a Sky Number.\n", n);
		else printf("%d is not a Sky Number.\n", n);
	}
	
	return 0;
}


