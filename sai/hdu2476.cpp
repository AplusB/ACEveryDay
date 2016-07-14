#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

const int MAXN=110;
int dp[MAXN][MAXN];//dp[i][j]表示涂i~j的最小次数
char str1[MAXN],str2[MAXN];
int ans[MAXN];//记录最小改变次数（关注的是改变二字）

int main()
{
    while(scanf("%s%s",str1,str2)==2)
    {
        int n=strlen(str1);
        memset(dp,0,sizeof(dp));

        //初始化，认为每个格子涂一次
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                dp[i][j]=j-i+1;

        //先直接DP求出从空白串变成str2
        for(int i=n-2;i>=0;i--)/***********************注意遍历顺序，满足无后效性************************/
		{
            for(int j=i+1;j<n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                for(int k=i+1;k<=j;k++)
				{
					 if(str2[i]==str2[k])//满足分开涂的条件
                        dp[i][j]=min(dp[i][j],dp[i+1][k-1]+dp[k][j]);//这里表示先把i~j底色涂为str2[i]，然后分成两段再去涂色
				}
            }
		}

		//一个一个的加入字符
        for(int i=0;i<n;i++)
        {
        	//初始化认为前i个字符全部需要改变
            ans[i]=dp[0][i];

            //如果单一的涂第i位（认为第i个完全完全不同）
            //如果出现相同字符则说明，该字符点处的最小值与之前相同（即 不用改变）
            if(str1[i]==str2[i])
            {
                if(i==0)
					ans[i]=0;
                else
					ans[i]=ans[i-1];
            }

            //如果分开涂（认为后j+1~i个完全不同）
            //遍历需要全部改变的区间 [i,j]
            for(int k=0;k<i;k++)
                ans[i]=min(ans[i],ans[k]+dp[k+1][i]);
        }
        printf("%d\n",ans[n-1]);
    }
    return 0;
}
