#include <bits/stdc++.h>
using namespace std;

int a[100];
int b[100];
bool vis1[100];
bool vis2[200];
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis1, false, sizeof(vis1));
        memset(vis2, false, sizeof(vis2));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &b[i]);
        sort(a + 1, a + 1 + n);
        sort(b + 1, b + 1 + n);
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            int j;
            for(j = n; j >= 1; --j)
            {
                if(vis2[j])
                    continue;
                if(a[i] > b[j])
                    break;
            }
            if(j >= 1)
            {
                ans += 2;
                vis1[i] = vis2[j] = true;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(vis1[i])
                continue;
            for(int j = 1; j <= n; ++j)
            {
                if(vis2[j])
                    continue;
                if(a[i] == b[j])
                {
                    vis1[i] = vis2[j] = true;
                    ++ans;
                    break;
                }
            }
        }
        printf("Case %d: %d\n", _case++, ans);
    }
    return 0;
}
