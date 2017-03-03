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

char a[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);
	int n;
	while (~scanf("%d", &n))
	{
		scanf("%s", a);
		string a1 = "", a2 = "";
		for (int i = n - 1; i >= 0; i--)
		{
			if ((n - 1 - i) % 2 == 0)
				a2 = a[i] + a2;
			else
				a1 = a1 + a[i];
		}
		cout << a1 << a2 << endl;
	}
	return 0;

}

