//lightoj	1169 - Monkeys on Twin Tower
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define mod 1000007  
#define inf 0x3f3f3f3f  
int a[1234],b[1234];  
int x[1234],y[1234];  
int dp[1234][2];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        int n;  
        scanf("%d",&n);  
        for(int i=0;i<n;i++)  
            scanf("%d",&a[i]);  
        for(int i=0;i<n;i++)  
            scanf("%d",&b[i]);  
        for(int i=1;i<n;i++)  
            scanf("%d",&x[i]);  
        for(int i=1;i<n;i++)  
            scanf("%d",&y[i]);  
        dp[0][0]=a[0],dp[0][1]=b[0];  
        for(int i=1;i<n;i++)  
        {  
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]+y[i])+a[i];
            dp[i][1]=min(dp[i-1][1],dp[i-1][0]+x[i])+b[i];
        }  
        printf("Case %d: %d\n",cas,min(dp[n-1][0],dp[n-1][1]));  
    }  
    return 0;  
}  
