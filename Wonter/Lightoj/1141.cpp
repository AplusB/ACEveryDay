#include <bits/stdc++.h>
using namespace std;

bool vis[1010];
int step[1010];
int bfs(int s, int t)
{
    if(s == t)
        return 0;
    memset(vis, false, sizeof(vis));
    queue<int> que;
    int tmp = s;
    for(int i = 2; i <= s; ++i)
    {
        if(s % i == 0 && i != tmp)
        {
            while(s % i == 0)
                s /= i;
            vis[tmp + i] = true;
            step[tmp + i] = 1;
            que.push(tmp + i);
        }
    }
    int ret = -1;
    while(que.size())
    {
        int now = que.front();
        que.pop();
        if(now == t)
        {
            ret = step[now];
            break;
        }
        tmp = now;
        for(int i = 2; i <= now; ++i)
        {
            if(now % i == 0 && i != tmp)
            {
                while(now % i == 0)
                    now /= i;
                if(tmp + i <= 1000 && !vis[tmp + i])
                {
                    que.push(tmp + i);
                    vis[tmp + i] = true;
                    step[tmp + i] = step[tmp] + 1;
                }
            }
        }
    }
    return ret;
}
int main()
{
    int T, _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        int s, t;
        scanf("%d%d", &s, &t);
        printf("Case %d: %d\n", _case++, bfs(s, t));
    }
    return 0;
}
