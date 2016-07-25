#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
const int maxn = 2e5 + 9;

int num[maxn];
int fa[maxn];

int find(int x);
int uu(int x, int y);

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int cnt = 0;
		for (int i = 0; i < maxn; i++) fa[i] = i;

		int root = -1;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			if (i == num[i]) root = i;
		}

		
		for (int i = 1; i <= n; i++)
		{
			if (i == num[i])
			{
				if (root == -1)
				{
					root = i;
				}
				else if(i!=root)
				{
					uu(root, i);
					num[i] = root;
					cnt++;
				}
			}
			else
			{
				int f1 = find(i), f2 = find(num[i]);
				if (f1 == f2)
				{
					if (root == -1)
					{
						root = i;
						num[i] = i;
						cnt++;
					}
					else
					{
						uu(root, i);
						num[i] = root;
						cnt++;

					}
				}
				else
				{
					uu(num[i],i);
				}
			}
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
				printf("%d", num[i]);
			else
				printf(" %d", num[i]);
		}
		printf("\n");
	}
	return 0;
}

int uu(int x, int y)
{
	int fx = find(x), fy = find(y);
	fa[fy] = fx;
	return 0;
}

int find(int x)
{
	if (fa[x] == x) return x;
	return fa[x]=find(fa[x]);
}
