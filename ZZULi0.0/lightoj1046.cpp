#include <bits/stdc++.h>
#define N 25
using namespace std;

char maze[N][N];
bool visit[N][N];
int m,n;
int dir[8][2] = {{1,2},{1,-2},{2,1},{2,-1},{-1,2},{-1,-2},{-2,1},{-2,-1}};
struct nodes
{
    int x,y,step;
} cur,tmp,chess[105];

bool judge(int x,int y)
{
    if(x < 0 || y < 0 || x >= m || y >= n || visit[x][y])
        return false;
    return true;
}
int BFS(int sx,int sy,int ex,int ey)
{
    memset(visit,0,sizeof(visit));
    cur.x = sx;
    cur.y = sy;
    visit[sx][sy] = 1;
    cur.step = 0;
    queue<nodes>Q;
    Q.push(cur);
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();
        if(cur.x == ex && cur.y == ey)
        {
            return cur.step;
        }

        for(int i = 0; i < 8; i++)
        {
            tmp.x = cur.x + dir[i][0];
            tmp.y = cur.y + dir[i][1];
            tmp.step = cur.step+1;
            if(judge(tmp.x,tmp.y))
            {
                visit[tmp.x][tmp.y] = 1;
                Q.push(tmp);
            }
        }
    }
    return -1;
}


void solve()
{
    int l = 0;
    scanf("%d %d",&m,&n);
    for(int i = 0; i < m; i++)
    {
        scanf("%s",maze[i]);
        for(int j = 0; j < n; j++)
        {
            if(isdigit(maze[i][j]))
            {
                chess[l].x = i;
                chess[l].y = j;
                chess[l++].step = maze[i][j] - '0';
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int curans = 0,flag = true;
            for(int k = 0; k < l; k++)
            {
                int tmp = BFS(chess[k].x,chess[k].y,i,j);
                if(tmp == -1)
                {
                    flag = false;
                    break;
                }
                curans += tmp/chess[k].step;
                tmp %= chess[k].step;
                if(tmp != 0)
                    curans++;
            }
            if(flag)
                ans = min(ans,curans);
        }
    }
    if(ans != INT_MAX)
        printf("%d\n",ans);
    else
        printf("-1\n");
}

int main(void)
{
    int t,cnt = 0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
}
