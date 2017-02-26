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

char a[maxn], b[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);
	while (~scanf("%s %s", a, b))
	{
		int alen = strlen(a), blen = strlen(b);
		if (strcmp(a, b) == 0) puts("-1");
		else
		{
			printf("%d\n", max(alen, blen));
		}
	}
	return 0;

}

