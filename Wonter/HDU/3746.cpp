#include <stdio.h>
#include <string.h>

char str[100010];
int next[100010];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", str + 1);
        int j = 0;
        next[1] = 0;
        for(int i = 2; str[i]; ++i)
        {
            while(j > 0 && str[j + 1] != str[i])
                j = next[j];
            if(str[j + 1] == str[i])
                ++j;
            next[i] = j;
        }
        int len = strlen(str + 1);
        if(next[len] >= (len + 1) >> 1 || len == 1)
        {
            int t = len - next[len];
            printf("%d\n", (t - len % t) % t);
        }
        else
            printf("%d\n", len - 2 * next[len]);
    }
    return 0;
}
