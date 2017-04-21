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

int ans[50];

int pre();

/*
int ok[50];

int deal(int len, int v,int now);
int judge(int len);
*/
int main()
{
	/*
	memset(ans, -1, sizeof(ans));
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 0;
	int len = 20;
	for (int i = 4; i <= len; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			for (int k = 1; k <= i; k++) ok[k] = 1;
			if (deal(i, j, 1) == 1)
			{
				ans[i] = j;
				break;
			}
		}
	}
	for (int i = 1; i <= len; i++)
	{
		printf("ans[%d]=%d;\n", i, ans[i]);
	}
	*/

	pre();
	int t;
	scanf("%d", &t);
	int cas = 1;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		printf("Case #%d: ", cas++);
		printf("%d\n", ans[n]);
	}
	
	return 0;
}

int pre()
{
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 0;
	ans[4] = 1;
	ans[5] = 1;
	ans[6] = 2;
	ans[7] = 3;
	ans[8] = 3;
	ans[9] = 4;
	ans[10] = 5;
	ans[11] = 6;
	ans[12] = 7;
	ans[13] = 7;
	ans[14] = 8;
	ans[15] = 9;
	ans[16] = 10;
	ans[17] = 11;
	ans[18] = 12;
	ans[19] = 13;
	ans[20] = 14;
	return 0;
}
/*
int deal(int len, int v,int now)
{
	if (v == 0)
		return judge(len);
	if (now > len && v != 0) return 0;

	int flag=deal(len, v, now + 1);
	if (flag == 0)
	{
		ok[now] = 0;
		flag = deal(len, v - 1, now + 1);
		ok[now] = 1;
	}
	return flag;
}

int judge(int len)
{
	for (int i = 1; i <= len; i++)
	{
		if (ok[i] == 0) continue;
		for (int j = i + 1; j <= len; j++)
		{
			if (ok[j] == 0) continue;
			for (int k = j + 1; k <= len; k++)
			{
				if (ok[k] == 0) continue;
				if (i + j > k)
				{
					return 0;
				}
			}
		}
	}
	return 1;
}
*/
