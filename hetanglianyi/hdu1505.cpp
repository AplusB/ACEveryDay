#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
const int N = 2000;
int a[N][N], l[N], r[N], n, m ;
int main()
{
    int t;
    char str[10];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            char s[100];
            scanf("%s", s);
            if(s[0] == 'F') a[i][j] = a[i-1][j] + 1;
        }
        int re = -1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
                l[j] = r[j] = j;
            a[i][0] = a[i][m+1] = -1;
            for(int j = 2; j <= m; j++)
            {
                while(a[i][j] <= a[i][l[j]-1]) l[j] = l[l[j]-1];
            }
            for(int j = m - 1; j >= 1; j--)
            {
                while(a[i][j] <= a[i][r[j]+1]) r[j] = r[r[j]+1];
            }
            for(int j = 1; j <= m; j++)
            {
                if(a[i][j] * (r[j] - l[j] + 1) > re) re = a[i][j] * (r[j] - l[j] + 1);
            }
        }
        printf("%d\n", re * 3);
    }
    return 0;
}
