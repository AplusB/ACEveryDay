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
	aha.clear();
	aha[0] = 'A', aha[1] = 'C', aha[2] = 'G', aha[3] = 'T';
	int n;
	while (~scanf("%d", &n))
	{

		memset(go, 0, sizeof(go));
		int cnt = 0;
		scanf("%s", num);
		int len = strlen(num);
		for (int i = 0; i < len; i++)
		{
			if (num[i] == '?') cnt++;
			else if (num[i] == 'A') go[0]++;
			else if (num[i] == 'C') go[1]++;
			else if (num[i] == 'G') go[2]++;
			else if (num[i] == 'T') go[3]++;
		}
		int maxx = 0;
		for (int i = 0; i < 4; i++)
			maxx = max(maxx, go[i]);
		int lt = 0;
		for (int i = 0; i < 4; i++)
			lt += maxx - go[i];
		if (lt > cnt || (cnt - lt) % 4 != 0)
		{
			puts("===");
			continue;
		}
		int up = maxx + (cnt - lt)/4;
		for (int i = 0; i < len; i++)
		{
			if (num[i] == '?')
			{
				for (int j = 0; j < 4; j++)
				{
					if (go[j] < up)
					{
						go[j]++;
						num[i] = aha[j];
						break;
					}
				}
			}
		}
		printf("%s\n", num);

	}

	return 0;

}

