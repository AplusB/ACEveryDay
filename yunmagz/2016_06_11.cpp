//lightoj	1125 - Divisible Group Sums
#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
#define mod 1000000007  
#define inf 0x3f3f3f3f  
ll dp[12][25];  
int a[300];  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        int n,q;  
        scanf("%d %d",&n,&q);  
        for(int i=1;i<=n;i++)  
            scanf("%d",&a[i]);  
        printf("Case %d:\n",cas);  
        while(q--)  
        {  
            int d,m;  
            scanf("%d %d",&d,&m);  
            memset(dp,0,sizeof(dp));  
            dp[0][0]=1LL;  
            for(int i=1;i<=n;i++)  
            {  
                int tmp=a[i]%d;  
                for(int j=m;j>=1;j--)  
                {  
                    for(int k=0;k<d;k++)  
                        dp[j][k]+=dp[j-1][(k+2*d-tmp)%d];  
                }  
  
            }  
            printf("%lld\n",dp[m][0]);  
        }  
    }  
    return 0;  
}  
