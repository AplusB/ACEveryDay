#include <bits/stdc++.h>
#define N 25
using namespace std;

char maze[N][N];
bool visit[N][N];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int n,sum;

struct nodes
{
    int x,y,step,alpha;
} cur,tmp;

bool judge(nodes tmp)
{
    int x = tmp.x,y = tmp.y;

    if(x < 0 || x >= n || y < 0 || y >= n || visit[x][y] || maze[x][y] == '#'
            || (isalpha(maze[x][y]) && maze[x][y] != 'A' + tmp.alpha))
        return false;
    return true;
}

int sx,sy;

int BFS(int x,int y,int goal)
{
    cur.x = x;
    cur.y = y;
    cur.alpha = goal;
    cur.step = 0;
    memset(visit,false,sizeof(visit));
    visit[x][y] = true;
    maze[x][y] = '.';

    queue<nodes>Q;
    Q.push(cur);
    while(!Q.empty())
    {
        nodes cur = Q.front();
        Q.pop();
        //printf("%d %d %c %d %c\n",cur.x,cur.y,'A'+cur.alpha,cur.step,maze[cur.x][cur.y]);

        if(maze[cur.x][cur.y] == 'A' + goal )
        {
            sx = cur.x;
            sy = cur.y;
            return cur.step;
        }

        for(int i = 0; i < 4; i++)
        {
            tmp.x = cur.x + dir[i][0];
            tmp.y = cur.y + dir[i][1];
            tmp.step = cur.step + 1;
            tmp.alpha = cur.alpha;
            if(judge(tmp))
            {
                visit[tmp.x][tmp.y] = true;
                Q.push(tmp);
            }
        }
    }
    return -1;
}

void solve()
{

    scanf("%d",&n);
    sum = 0;
    memset(visit,false,sizeof(visit));
    for(int i = 0; i < n; i++)
        scanf("%s",maze[i]);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(isalpha(maze[i][j]))
            {
                sum++;
                if(maze[i][j] == 'A')
                    sx = i,sy = j;
            }
        }
    }
    int ans = 0;
    bool flag = true;
    for(int i = 1; i < sum; i++)
    {
        int tmp = BFS(sx,sy,i);
        if(tmp == -1)
        {
            flag = false;
            break;
        }
        ans += tmp;
    }
    if(flag)
        printf("%d\n",ans);
    else
        printf("Impossible\n");
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
