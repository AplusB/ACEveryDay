#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
typedef long long ll;

const int maxn = 5e5 + 9;
const ll inf = 1e15;

set<int> aha;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		aha.clear();
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			aha.insert(x);
		}
		//sort(aha.begin(), aha.end());
		if (aha.size() < 3) puts("-1");
		else
		{
			set<int>::iterator it;
			it = aha.begin();
			++it;
			++it;
			printf("%d\n", *it);
		}
	}
	return 0;
}
