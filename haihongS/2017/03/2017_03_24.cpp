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
const int maxn = 2e2 + 9;
const ll inf = 1e9 + 9;

set<string> aha;


int main()
{
	//std::ios::sync_with_stdio(false);

	string x;

	int t;
	scanf("%d", &t);
	while (t--)
	{
		string a;
		cin >> a;
		cout << 6 << a.substr(6, 5) << endl;
	}
	return 0;

}
