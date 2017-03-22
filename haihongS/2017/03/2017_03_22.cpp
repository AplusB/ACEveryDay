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
const int maxn = 2e2 + 9;
const ll inf = 1e9 + 9;



int main()
{
	//std::ios::sync_with_stdio(false);

	ll down = -10000, up = 10000;

	ll n, m;
	while (~scanf("%lld %lld",&n,&m) && n + m)
	{
		int flag = 0;
		for (ll i = down; i <= up; i++)
		{
			if (i*i - n*i + m == 0)
			{
				flag = 1; break;
			}
		}
		if (flag==1) puts("Yes");
		else puts("No");
	}
	return 0;

}
