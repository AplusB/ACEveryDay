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
		priority_queue<int> aha;
		while (!aha.empty()) aha.pop();
		int flag = n;
		for (int i = 0; i < n; i++)
		{
			aha.push(a[i]);
			int ok = 0;
			while (!aha.empty() && aha.top() == flag)
			{
				flag--;
				if (ok == 1) printf(" ");
				ok = 1;
				printf("%d", aha.top());
				aha.pop();
			}
			puts("");
		}
		
	}
	return 0;

}

