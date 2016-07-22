#include <stdio.h>
#include <string.h>

char a[300], b[300], c[500];
int len_a;
int len_b;
int dp[210][210];
int dfs(int i, int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == len_a && j == len_b)
        return dp[i][j] = 1;
    int k = i + j;
    dp[i][j] = 0;
    if(c[k] == a[i])
        dp[i][j] += dfs(i + 1, j);
    if(c[k] == b[j])
        dp[i][j] += dfs(i, j + 1);
    return dp[i][j];
}
int main()
{
    int _case = 1;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%s%s%s", a, b, c);
        len_a = strlen(a);
        len_b = strlen(b);
        if(dfs(0, 0))
            printf("Data set %d: yes\n", _case++);
        else
            printf("Data set %d: no\n", _case++);
    }
    return 0;
}
