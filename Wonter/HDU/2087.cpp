#include <bits/stdc++.h>
using namespace std;

char str1[2000];
char str2[2000];
int f[10000000];
int main()
{
    while(scanf("%s", str1), str1[0] != '#')
    {
        scanf("%s", str2);
        int j = -1;
        f[0] = -1;
        for(int i = 1; str2[i]; ++i)
        {
            while(j > -1 && str2[j + 1] != str2[i])
                j = f[j];
            if(str2[j + 1] == str2[i])
                ++j;
            f[i] = j;
        }
        j = -1;
        int ans = 0;
        for(int i = 0; str1[i]; ++i)
        {
            while(j > -1 && str2[j + 1] != str1[i])
                j = f[j];
            if(str2[j + 1] == str1[i])
                ++j;
            if(str2[j + 1] == '\0')
            {
                ++ans;
                j = -1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
