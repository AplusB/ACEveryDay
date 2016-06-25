//lightoj1421 - Wavio Sequence
#include<bits/stdc++.h>
using namespace std;  
const int INF = 0x3f3f3f3f;  
const int maxn = 1e5+5;  
  
int n,a[maxn],b[2][maxn],dp[maxn];  
  
int main(){  
    int i,j,cas,T;  
    scanf("%d",&cas);  
    for(T = 1;T <= cas;T++){  
        scanf("%d",&n);  
        for(i = 1;i <= n;i++) scanf("%d",&a[i]);  
        memset(dp,63,sizeof(dp));  
        int p;  
        for(i = 1;i <= n;i++){  
            p = lower_bound(dp,dp+n,a[i])-dp;  
            b[0][i] = p+1;  
            dp[p] = a[i];  
        }  
        memset(dp,63,sizeof(dp));  
        for(i = n;i >= 1;i--){  
            p = lower_bound(dp,dp+n,a[i])-dp;  
            b[1][i] = p+1;  
            dp[p] = a[i];  
        }  
        int res = 0;  
        for(i = 1;i <= n;i++){  
            res = max(res,2*min(b[0][i],b[1][i])-1);  
        }  
        printf("Case %d: %d\n",T,res);  
    }  
  
    return 0;  
}  
