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

const int maxn = 2e5 + 9;

char a[maxn];
int ans[maxn];

int main()
{
	while (~scanf("%s", a))
	{
		int len = strlen(a);
		int now = 0, pos = 0, flag = 0;
		for (int i = 0; i < len; i++)
		{
			if (a[i] == '5')
			{
				if (flag == 1)
				{
					ans[pos++] = now;
					now = 0;
					flag = 0;	
				}
				continue;
			}
			flag = 1;
			now = now * 10 + a[i] - '0';
		}
		if(flag==1)
			ans[pos++] = now;
		sort(ans, ans + pos);
		for (int i = 0; i < pos; i++)
		{
			if (i != 0) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
	return 0;
}

