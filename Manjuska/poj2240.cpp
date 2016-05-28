#include<iostream>
#include<string.h>
#include<string>
#include<map>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int maxn = 40;
double d[maxn];
int n, m;
double w[maxn][maxn];
map<string, int>mp;
void floyd()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				w[i][j] = max(w[i][j], w[i][k] * w[k][j]);
}
int main()
{
	int kcase = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		mp.clear();
		string s;
		for(int i=1;i<=n;i++)
		{
			cin >> s;
			mp[s] = i;
			w[i][i] = 1;
		}
		scanf("%d", &m);
		string s1, s2;
		double rat;
		for (int i = 0; i < m; i++)
		{
			cin >> s1 >> rat >> s2;
			w[mp[s1]][mp[s2]] = rat;
		}

		floyd();

		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			if (w[i][i] > 1.0)
			{
				flag = 1; break;
			}
		}
		printf("Case %d: ", ++kcase);
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
