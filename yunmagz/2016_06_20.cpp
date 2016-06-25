//CF#358 (Div. 2) D
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char s[N],t[N];
int dp[2][N][N][12];
int main()
{
    int i,j,h,l,n,m,k;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s", s);
    scanf("%s", t);
    memset(dp,0,sizeof(dp));
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        if (s[i-1]!=t[j-1]) {
            for (h=0;h<=k;h++)
                for (l=0;l<2;l++)
                dp[0][i][j][h]=max(dp[0][i][j][h],max(dp[l][i][j-1][h],dp[l][i-1][j][h]));
        } else {
            for (h=0;h<=k;h++) {
                dp[0][i][j][h]=max(dp[0][i][j][h],max(dp[1][i][j-1][h],dp[1][i-1][j][h]));
                dp[0][i][j][h]=max(dp[0][i][j][h],max(dp[0][i][j-1][h],dp[0][i-1][j][h]));
                dp[1][i][j][h]=max(dp[1][i][j][h],dp[0][i-1][j-1][h-1]+1);
                dp[1][i][j][h]=max(dp[1][i][j][h],dp[1][i-1][j-1][h]+1);
            }
        }
    printf("%d\n", max(dp[0][n][m][k-1],dp[1][n][m][k-1]));
    return 0;
}
