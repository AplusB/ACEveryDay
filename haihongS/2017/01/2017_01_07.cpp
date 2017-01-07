#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 3e5 + 9;
const ll inf = 1e9 + 9;

char jj[5] = { '1','0','l','O' };
char ok[5] = { '@','%','L','o' };

struct II
{
	char name[20], pwd[20];
};

vector<II> aha;

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		aha.clear();
		for (int i = 0; i < n; i++)
		{
			char name[20], pwd[20];
			scanf("%s%s", name, pwd);
			int len2 = strlen(pwd);
			int flag = 0;
			for (int j = 0; j < len2; j++)
			{
				for (int k = 0; k < 4; k++)
				{
					if (pwd[j] == jj[k])
					{
						flag = 1;
						pwd[j] = ok[k]; break;
					}
				}
			}
			if (flag == 1)
			{
				II now;
				strcpy(now.name, name);
				strcpy(now.pwd, pwd);
				aha.push_back(now);
			}
		}
		int len = aha.size();
		if (len == 0)
		{
			if(n==1)
				printf("There is 1 account and no account is modified\n");
			else 
				printf("There are %d accounts and no account is modified\n", n);
		}
		else
		{
			printf("%d\n", len);
			for (int i = 0; i < len; i++)
				printf("%s %s\n", aha[i].name, aha[i].pwd);
		}
	}
	return 0;
}
