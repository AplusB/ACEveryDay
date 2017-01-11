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

string a, b, c;
map<char, int> aha;

int main()
{
	std::ios::sync_with_stdio(false);
	while (getline(cin, a))
	{
		getline(cin, b);
		aha.clear();
		int alen = a.length(), blen = b.length();
		c = "";
		for (int i = 0; i < blen; i++)
			aha[b[i]] = 1;
		for (int i = 0; i < alen; i++)
		{
			if (aha[a[i]] == 0) c += a[i];
		}
		cout << c << endl;
	}

	return 0;
}
