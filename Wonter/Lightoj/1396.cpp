#include <bits/stdc++.h>
using namespace std;

char str[100050];
int vis[100050];
int len;
bool Check(int e)
{
    if(vis[e] != -1)
        return vis[e];
    if(len - e + 1 >= e)
        return vis[e] = 1;
    if(str[e] == str[len - e + 1])
        return vis[e] = Check(e - 1);
    return vis[e] = 0;
}
void Slove()
{
    len = strlen(str + 1);
    for(int i = len;i >= 1;--i)
    {
        if(Check(i - 1))
        {
            if(i <= (len + 1) >> 1 && str[i] < '9')
            {
                ++str[i];
                for(int j = len;j > len - i;--j)
                    str[j] = str[len - j + 1];
                for(int j = i + 1;j <= len - i;++j)
                    str[j] = '0';
                printf("%s\n", str + 1);
                return ;
            }
            if(i > (len + 1) >> 1 && str[i] < str[len - i + 1] && Check(i - 1))
            {
                str[i] = str[len - i + 1];
                for(int j = i + 1;j <= len;++j)
                    str[j] = str[len - j + 1];
                printf("%s\n", str + 1);
                return ;
            }
        }
    }
    if(strcmp(str + 1, "9") == 0)
    {
        puts("11");
        return ;
    }
    str[1] -= '0';
    ++str[1];
    printf("%d", str[1]);
    for(int i = 2;i <= len;++i)
    {
        if(i != len)
            printf("0");
        else
            printf("1");
    }
    printf("\n");
}
int main()
{
    int _case = 1;
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, -1, sizeof(vis));
        scanf("%s", str + 1);
        printf("Case %d: ", _case++);
        Slove();
    }
    return 0;
}
