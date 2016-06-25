#include <bits/stdc++.h>
using namespace std;

char str[200];
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(str, 0, sizeof(str));
        int n;
        scanf("%d", &n);
        scanf("%s", str);
        int ans = 0;
        for(int i = 0; str[i]; ++i)
        {
            if(str[i] == '.')
            {
                str[i] = str[i + 1] = str[i + 2] = '#';
                ++ans;
            }
        }
        printf("Case %d: %d\n", _case++, ans);
    }
    return 0;
}
