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


int main()
{
	//std::ios::sync_with_stdio(false);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char x[10];
		scanf("%s", x);
		int y;
		scanf("%d", &y);
		if ('A' <= x[0] && x[0] <= 'Z')
		{
			printf("%d\n", y + x[0] - 'A' + 1);
		}
		else
			printf("%d\n", y - (x[0] - 'a' + 1));
	}
	return 0;

}

