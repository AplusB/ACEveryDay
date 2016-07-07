//DP基础

/*

看题解A的。
总结：小矩阵--> 大矩阵

dp[i][j]=min(t,dp[i-1][j+1]+1); 

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define MAX 100010
#define mod 9973
#define LL long long

const int N=1e3+10;

char a[N][N];
int dp[N][N];
int n;

int main()
{
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%s",a[i]+1);		
			for(int j=1;j<=n;j++)
				dp[i][j]=0;
		}
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==1&&j==n)
					dp[i][j]=1;
				else{
					int t1=i,t2=j;
					while(t1>=1&&t2<=n&&a[t1][j]==a[i][t2]){
						t1--;
						t2++;
					}
					int t=i-t1;
					if(t>dp[i-1][j+1]+1)			//这一步其实就是，你想一下大矩阵只满足最外面的上和右对称，但是不能保证里面的对称，所以取这样 
						dp[i][j]=dp[i-1][j+1]+1;
					else
						dp[i][j]=t;					//这里就是大矩阵上和右达不到小矩阵对称长度。 
					ans=max(ans,dp[i][j]);
				}
			}
		}
		
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf("%d ",dp[i][j]);
			puts("");
		}*/
		
		cout<<ans<<endl;
	}
	return 0;
}
 

 


