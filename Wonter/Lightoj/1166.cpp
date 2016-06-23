#include <bits/stdc++.h>
using namespace std;

int a[200];
int nxt[200];
bool vis[200];
int dfs(int cur)
{
    vis[cur] = true;
    if(vis[nxt[cur]])
        return 1;
    return dfs(nxt[cur]) + 1;
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        memset(vis, false, sizeof(vis));
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n;++i)
            scanf("%d", &a[i]);
        for(int i = 1;i <= n;++i)
            nxt[ a[i] ] = i;
        int ans = 0;
        for(int i = 1;i <= n;++i)
            if(!vis[i])
                ans += dfs(i) - 1;
        printf("Case %d: %d\n", _case++, ans);
    }
    return 0;
}
