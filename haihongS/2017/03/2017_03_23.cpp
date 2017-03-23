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
	while (getline(cin, x))
	{
		if (x == "#") break;
		int len = x.size();
		aha.clear();
		int ans = 0;
		string now = "";
		for (int i = 0; i < len; i++)
		{
			if (x[i] == ' ')
			{
				if(now!="")
					aha.insert(now);
				now = "";
			}
			else
				now = now + x[i];
		}
		if(now!="") aha.insert(now);
		ans = aha.size();
		
		printf("%d\n", ans);

	}
	return 0;

}
