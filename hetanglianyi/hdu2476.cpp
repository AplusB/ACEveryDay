#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 110;
char s1[N],s2[N];
int f[N][N];
int ans[N],len;

int main()
{
    while(scanf("%s%s", s1, s2) != EOF)
    {
        int len = strlen(s1);
        memset(f, 0, sizeof(f));
        for(int j = 0; j < len; j++)
        {
            for(int i = j; i >= 0; i--)
            {
                f[i][j] = f[i+1][j] + 1;
                for(int k = i + 1; k <= j; k++)
                {
                    if(s2[i] == s2[k]) f[i][j] = min(f[i][j], (f[i+1][k] + f[k+1][j]));
                }
            }
        }
        for(int i = 0; i < len; i++)
            ans[i] = f[0][i];
        for(int i = 0; i < len; i++)
        {
            if(s1[i] == s2[i]) ans[i] = ans[i-1];
            else
            {
                for(int j = 0; j < i; j++)
                    ans[i] = min(ans[i], ans[j] + f[j+1][i]);
            }
        }
        printf("%d\n", ans[len-1]);
    }

    return 0;
}
