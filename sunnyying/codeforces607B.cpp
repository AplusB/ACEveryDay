#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 200000+10
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod  1000000007
#define ll unsigned long long
#define eps 1e-10
using namespace std;
int a[600],dp[600][600];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),dp[i][1]=1;
    for(int l=2;l<=n;l++)
    {
        for(int i=1;i+l-1<=n;i++)
        {
            dp[i][l]=l;
            for(int j=i;j<=i+l-1;j++)
            {
                dp[i][l]=min(dp[i][l],dp[i][j-i+1]+dp[j+1][i+l-1-j]);
               // cout<<i<<" "<<j<<" "<<i+l-1<<" "<<dp[i][l]<<" "<<dp[i][j-i+1]<<" "<<dp[j+1][i+l-1-j]<<endl;
            }
            if(a[i]==a[i+l-1]) dp[i][l]=min(dp[i][l],dp[i+1][l-2]);
            if(i+1==i+l-1&&a[i]==a[i+l-1]) dp[i][l]=1;
         //   cout<<i<<" "<<i+l-1<<" "<<dp[i][l]<<endl;
        }
    }
    cout<<dp[1][n]<<endl;
    return 0;
}
