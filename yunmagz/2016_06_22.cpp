//lightoj	1326 - Race
#include <bits/stdc++.h>  
using namespace std;
int dp[1010][1010];  
int aa[1010];  
int main()  
{  
    int t,n;  
    int mod=10056;  
    scanf("%d",&t);  
    int cas=1;  
    int ans;  
    n=1000;  
    memset(dp,0,sizeof dp);  
    dp[1][1]=1;  
    for(int i=2;i<=n;i++) 
    {  
        for(int j=1;j<=i;j++)
        {  
            dp[i][j]+=(dp[i-1][j]*j+dp[i-1][j-1]*j)%mod;  
        }  
    }   
  
    for(int i=1;i<=n;i++)  
    {   
        ans=0;  
        for(int j=1;j<=i;j++)  
        {   
            ans=(ans+dp[i][j])%mod;;  
        }  
        aa[i]=ans;  
    }   
    while(t--)  
    {  
        scanf("%d",&n);   
        printf("Case %d: %d\n",cas++,aa[n]);  
    }  
    return 0;  
}  
