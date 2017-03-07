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

int a[maxn], b[maxn];


int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		b[n] = -1;
		for (int i = n - 1; i >= 0; i--)
			b[i] = max(b[i + 1], a[i]);
		stack<int> aha;
		while (!aha.empty()) aha.pop();
		for (int i = 0; i < n; i++)
		{
			if (a[i] == b[i])
			{
				printf("%d", a[i]);
				while (!aha.empty())
				{
					printf(" %d", aha.top());
					aha.pop();
				}
				puts("");
			}
			else
			{
				aha.push(a[i]);
				puts("");
			}				
		}
		
	}
	return 0;

}

