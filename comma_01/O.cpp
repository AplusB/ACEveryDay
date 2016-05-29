#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 2000 + 3;
int v[MAX], dp[MAX][MAX];
 
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &v[i]);
    
    for (int i = n; i >= 1; --i) {
        for (int j = i; j <= n; ++j) {
            dp[i][j] = max(dp[i+1][j] + v[i] * (n + i - j), dp[i][j-1] + v[j] * (n + i - j));
        }
    }       
    
    printf("%d\n", dp[1][n]);
    
    return 0;
}