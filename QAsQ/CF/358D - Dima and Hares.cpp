#include<bits/stdc++.h>
using namespace std;

const int maxn = 3123; 
int a[maxn],b[maxn],c[maxn];
int dp[2][maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i ++) scanf("%d",&a[i]);
    for(int i = 1; i <= n; i ++) scanf("%d",&b[i]);
    for(int i = 1; i <= n; i ++) scanf("%d",&c[i]);
    dp[0][1] = a[1],dp[1][1] = b[1];
    for(int i = 2 ; i <= n;i++){
        dp[0][i] = max(dp[0][i-1] + b[i],dp[1][i-1] + a[i]);
        dp[1][i] = max(dp[0][i-1] + c[i],dp[1][i-1] + b[i]);
    }
    printf("%d\n",dp[0][n]);
    return 0;
}
