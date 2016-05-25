#include<iostream>
#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;
char str[1000];
char word[1000][30];
int dp[1000];
int main()
{
	int n, len, i, j, pos, k, tmp;
	while(scanf("%d%d",&n,&len)!=EOF)
	{
		scanf("%s", str);
		for(i=0;i<n;i++)
		{
			scanf("%s", word[i]);
		}
		dp[0] = 0;
		for(i=1;i<=len;i++)
		{
			dp[i] = dp[i - 1] + 1;
			for(j=0;j<n;j++)
			{
				tmp = k = strlen(word[j]);
				k -= 1;
				pos = i - 1;
				while (pos>=0&&k>=0)
				{
					if(str[pos]==word[j][k])
					{
						k--;
					}
					pos--;
				}
				if (k<0)
				{      //可以匹配出一个单词  
					dp[i] = min(dp[i], dp[pos + 1] + i - pos - 1 - tmp);
				}
			}
		}
		cout << dp[len] << endl;
	}
	return 0;
}
