#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int f[1010][1010];
int n;
char s[1010];

int main()
{
    gets(s);
    n = strlen(s);
    int maxn = 1;
    for (int i = 0; i < n; i++)
        f[i][i] = 1;
    for (int i = 0; i < n-1; i++)
        if (s[i] == s[i+1]) {f[i][i+1] = 1; maxn = 2;}
        else f[i][i+1] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 0; i+l < n;i++)
        {
            int j = i+l;
            if (s[i] == s[j] && f[i+1][j-1])
            {
                f[i][j] = 1; maxn = l+1;
            }
        }
    }
    printf("%d", maxn);
    return 0;
}
