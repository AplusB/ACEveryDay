#include <bits/stdc++.h>
using namespace std;

int a[10050];
int cnt[1000500];
int n;
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            ++cnt[ a[i] ];
        }
        bool ans;
        ans = true;
        for(int i = 1; i <= n; ++i)
            if(a[i] >= n)
                ans = false;
        if(!ans)
        {
            printf("Case %d: no\n", _case++);
            continue;
        }
        ans = true;
        for(int i = 1; i <= n; ++i)
            if(cnt[i] + cnt[n - i - 1] >= 3)
                ans = false;
        if(!ans)
            printf("Case %d: no\n", _case++);
        else
            printf("Case %d: yes\n", _case++);
    }
    return 0;
}
