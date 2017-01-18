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
const int maxn = 4e2 + 9;
const ll inf = 1e9 + 9;


int main()
{
	//std::ios::sync_with_stdio(false);
	int n, t;
	scanf("%d%d", &n, &t);
	if (n == 1 && t == 10)
	{
		printf("-1\n");
		return 0;
	}
	if (n == 1 || (n==2 && t==10))
	{
		printf("%d\n", t);
	}
	else
	{
		if (t != 10)
		{
			for (int i = 0; i < n; i++) printf("%d",t);
		}
		else
		{
			printf("1");
			for (int i = 0; i < n - 1; i++) printf("0");
		}
		printf("\n");
	}

	
	return 0;

}

