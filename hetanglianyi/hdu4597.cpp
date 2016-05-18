#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int num1[40], num2[40], sum1[40] ,sum2[40];
int f[40][40][40][40];
int n;
int dfs(int i, int j, int k, int h)
{
    int sum = sum1[j] - sum1[i-1] + sum2[h] - sum2[k-1];
    if(f[i][j][k][h] != 0) return f[i][j][k][h];
    int re = 0;
    if(i < j)
    {
        re = max(re, sum - dfs(i+1,j,k,h));
        re = max(re, sum - dfs(i,j-1,k,h));
    }
    if(i == j) re = max(re, sum - dfs(i+1,j,k,h));
    if(k < h)
    {
        re = max(re, sum - dfs(i,j,k+1,h));
        re = max(re, sum - dfs(i,j,k,h-1));
    }
    if(k == h) re = max(re, sum-dfs(i,j,k+1,h));
    return f[i][j][k][h] = re;
}

int main()
{
   int t;
   cin >> t;
   while(t--)
   {
       memset(f, 0, sizeof(f));
       scanf("%d", &n);
       for(int i = 1; i <= n; i++)
       {
           scanf("%d", &num1[i]);
           sum1[i] = sum1[i-1] + num1[i];
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &num2[i]);
            sum2[i] = sum2[i-1] + num2[i];
        }
       cout << dfs(1,n,1,n) << endl;
   }
    return 0;
}
