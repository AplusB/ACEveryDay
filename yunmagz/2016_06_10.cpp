//lightoj	1159 - Batman
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define mod 1000007  
#define inf 0x3f3f3f3f  
char s1[60],s2[60],s3[60];  
int dp[60][60][60];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        scanf("%s %s %s",s1+1,s2+1,s3+1);  
        int len1=strlen(s1+1);  
        int len2=strlen(s2+1);  
        int len3=strlen(s3+1);  
        memset(dp,0,sizeof(dp));  
        for(int i=1;i<=len1;i++)  
        {  
            for(int j=1;j<=len2;j++)  
            {  
                for(int k=1;k<=len3;k++)  
                {  
                    if(s1[i]==s2[j]&&s3[k]==s1[i])  
                        dp[i][j][k]=dp[i-1][j-1][k-1]+1;  
                    else  
                        dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));  
                }  
            }  
        }  
        printf("Case %d: %d\n",cas,dp[len1][len2][len3]);  
    }  
    return 0;  
}  
