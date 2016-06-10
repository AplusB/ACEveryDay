#include <stdio.h>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

typedef pair<int,int> P;
char str[60][60];
int m, n;
bool vis[60][60];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(char ch)
{
    memset(vis, false, sizeof(vis));
    queue<P> que;
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if(str[i][j] != ch)
            {
                que.push(P(i, j));
                vis[i][j] = true;
            }
    queue<P>::size_type cnt = 0;
    while(que.size())
    {
        P now = que.front();
        ++cnt;
        if(cnt > que.size())
            break;
        bool flag = false;
        for(int i = 0; i < 4;++i)
        {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];
            if(!(nx >= 1 && nx <= m && ny >= 1 && ny <= n))
                flag = true;
            else if(vis[nx][ny] == false && str[nx][ny] != ch)
                flag = true;
            if(flag)
                break;
        }
        if(flag)
        {
            vis[now.first][now.second] = false;
            que.pop();
            cnt = 0;
        }
        else
        {
            que.push(now);
            que.pop();
        }
    }
    while(que.size())
    {
        P now = que.front();
        que.pop();
        str[now.first][now.second] = ch;
    }
}
int main()
{
    int T;
    int _case = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &m, &n);
        for(int i = 1; i <= m; ++i)
            scanf("%s", str[i] + 1);
        for(int i = 0; i < 26; ++i)
            bfs(static_cast<char>('A' + i));
        printf("Case %d:\n", _case++);
        for(int i = 1;i <= m;++i)
            puts(str[i] + 1);
    }
    return 0;
}
