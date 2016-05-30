#include<iostream>
using namespace std;
char pic[8][8];
int col[8];
int c;
int n, k;
void dfs(int begin,int num)
{
	for(int j=0;j<n;j++)
	{
		if(pic[begin][j]=='#'&&col[j]==0)
		{
			if (num == 1)
				c++;
			else
			{
				col[j] = 1;
				for (int h = begin + 1; h<n - num + 2; h++)
					dfs(h, num - 1);
				col[j] = 0;
			}
		}
	}
}
int main()
{
	while ((cin >> n >> k) && !(n == -1 && k == -1))
	{
		c = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++)
				cin >> pic[i][j];
		for (int i = 0; i<n; i++)
			col[i] = 0;
		for (int i = 0; i <= n - k; i++) 
		{
			dfs(i, k);
		}
		cout << c << endl;
	}
	return 0;
}
