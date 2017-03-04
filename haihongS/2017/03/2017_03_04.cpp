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

map<string, int> aha;

int main()
{
	//std::ios::sync_with_stdio(false);
	string a;
	while (cin >> a)
	{
		aha.clear();
		int cnt = 0, len = a.size();
		while (aha[a] == 0)
		{
			cnt++;
			aha[a] = 1;
			string::iterator it;
			string tmp = a[len-1] + a;
			it = tmp.end();
			--it;
			tmp.erase(it);
			a = tmp;
		}
		printf("%d\n", cnt);

	}
	return 0;

}

