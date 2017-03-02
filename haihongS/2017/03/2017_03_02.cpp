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

char num[maxn];
int go[10];
map<int, char> aha;

int main()
{
	//std::ios::sync_with_stdio(false);
	int a, b, c;
	while (~scanf("%d%d%d", &a, &b, &c))
	{
		int num[5] = { 0 };
		num[0] = a / 1, num[1] = b / 2, num[2] = c / 4;
		int minn = 1000000;
		for (int i = 0; i < 3; i++)
			minn = min(minn, num[i]);
		printf("%d\n", minn * 7);
	}
	return 0;

}

