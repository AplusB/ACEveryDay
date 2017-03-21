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

/*
map<string, int> aha;
map<ll, string> ans;
*/


int main()
{
	//std::ios::sync_with_stdio(false);

	/*
	freopen("see.txt", "w", stdout);
	aha.clear();
	ans.clear();
	ll up = 30000;
	for (ll i = 1989; i <= up; i++)
	{
		ll now = i;
		string tmp = "";
		while (now > 0)
		{
			tmp = (char)(now % 10 + '0') + tmp;
			now /= 10;
			if (aha[tmp] == 0)
			{
				aha[tmp] = 1;
				ans[i] = tmp;
				break;
			}
		}
	}
	for (ll i = 1989; i <= up; i++)
	{
		cout << i << " " << ans[i] << endl;
	}
	return 0;
	*/


	int n;
	scanf("%d", &n);
	while(n--)
	{
		string a;
		cin >> a;
		int len = a.size();
		a = a.substr(4, len - 4);
		len = a.size();

		ll x = 0;
		for (int i = 0; i < len; i++)
		{
			x = x * 10LL + (a[i] - '0') * 1LL;
		}
		
		ll ans = 0, pos = 10LL;
		for (int i = 0; i < len-1 ; i++)
		{
			ans += pos;
			pos *= 10LL;
		}

		while (x < 1989 + ans) x += pos;

		printf("%lld\n", x);



	}
	return 0;

}
