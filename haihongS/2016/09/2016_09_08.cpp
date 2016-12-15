#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>

using namespace std;
const int maxn = 2e5 + 9;

int x[maxn], y[maxn];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &x[i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &y[i]);
		map<int, int> aha;
		aha.clear();
		int pos = 0, last = 0;
		int ff = 0, cnt = 0;
		
		while (pos < n)
		{
			if (aha[x[pos]] == 1)
			{
				aha[x[pos]]--;
				cnt--;
			}
			else
			{
				aha[x[pos]]++;
				cnt++;
			}
			if(aha[y[pos]]==1)
			{
				aha[y[pos]]--; cnt--;
			}
			else
			{
				aha[y[pos]]++; cnt++;
			}
			if (cnt == 0)
			{
				if (ff == 0) ff = 1;
				else printf(" ");
				printf("%d-%d", last+1, pos+1);
				last = pos + 1;
			}
			pos++;
		}
		printf("\n");
	}
	return 0;
}
