#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define endl '\n'

using namespace std;

const int MAXN = 5005;

int dp[2][MAXN];
int n;
char s1[MAXN],s2[MAXN];

int main()
{
	while(scanf("%d",&n) == 1)
	{
		scanf("%s",s1);
		
		int i,j;
		for(i = 0;i < n;i++)
		{
			s2[i] = s1[n - 1 - i];
			//cout << s2[i] << endl;
		}
		s2[n] = '\0';
		//cout << endl;
		
		//printf("%s\n",s1);
		//printf("%s\n",s2);
		
		memset(dp,0,sizeof(dp));
		int cur = 0;
		for(i = 0;i < n;i++)
		{
			cur = (!cur);
			for(j = 0;j < n;j++)
			{
				if(s1[i] == s2[j])
				{
					dp[!cur][j + 1] = dp[cur][j] + 1; 
				}
				else
				{
					dp[!cur][j + 1] = max(dp[!cur][j],dp[cur][j + 1]);
				}
			}
		}
		
		cout << n - dp[!cur][n] << endl;
	}
	return 0;
} 
