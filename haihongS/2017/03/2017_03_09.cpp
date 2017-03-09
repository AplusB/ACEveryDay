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

stack<int> aha;

int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n))
	{
		while (!aha.empty())
		{
			aha.pop();
		}
		while (n)
		{
			aha.push(n % 2);
			n /= 2;
		}
		while (!aha.empty())
		{
			printf("%d", aha.top());
			aha.pop();
		}
		puts("");
	}
	return 0;

}

