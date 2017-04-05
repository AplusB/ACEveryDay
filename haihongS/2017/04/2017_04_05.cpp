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
const int maxn = 3e5 + 9;
const double eps = 1e-5;
const double inf = 1e9 + 9;
const ll mod = 7;

int a[maxn];
vector<pair<string, string> > ans;

int main()
{
	//std::ios::sync_with_stdio(false);

	ans.clear();
	
	string a, b;
	cin >> a >> b;
	ans.push_back(make_pair(a, b));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string x, y;
		cin >> x >> y;
		if (x == a)
			a = y;
		else
			b = y;
		ans.push_back(make_pair(a, b));
	}
	int len = ans.size();
	for (int i = 0; i < len; i++)
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;

}
