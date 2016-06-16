#include <stdio.h>
#include <string.h>

int next[200010];
int cnt[200010];
char s[200010];
int sum[200010];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        memset(sum, 0, sizeof(sum));
        int n;
        scanf("%d", &n);
        scanf("%s", s + 1);
        int j = 0;
        next[1] = 0;
        cnt[1] = 1;
        for(int i = 2; s[i]; ++i)
        {
            while(j > 0 && s[j + 1] != s[i])
                j = next[j];
            if(s[j + 1] == s[i])
                ++j;
            next[i] = j;
            cnt[i] = 1;
        }
        for(int i = n;i >= 1;--i)
            cnt[next[i]] = (cnt[next[i]] + cnt[i]) % 10007;
        int ans = 0;
        for(int i = 1;i <= n;++i)
            ans = (ans + cnt[i]) % 10007;
        printf("%d\n", ans);
    }
    return 0;
}
