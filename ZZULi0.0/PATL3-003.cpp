#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <queue>
#include <algorithm>
#define N 25
#define LL long long
using namespace std;
int maze[65][1500][150];
bool visit[65][1500][150];
int m,n,l,t,ans;
int dir[6][3] = {{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{-1,0,0},{1,0,0}};
bool judge(int x,int y ,int z)
{
    if(x < 0 || x >= l || y < 0 || y >= m || z < 0 || z >= n || visit[x][y][z] || maze[x][y][z] == 0)
        return false;
    return true;
}

struct nodes
{
    int x,y,z;
}cur,tmp;

int bfs(int x,int y,int z)
{
    visit[x][y][z] = 1;
    cur.x = x;
    cur.y = y;
    cur.z = z;
    queue<nodes>Q;
    Q.push(cur);
    int sum = 1;
    while(!Q.empty())
    {
        cur = Q.front();
        Q.pop();

        for(int i = 0; i < 6; i++)
        {
            tmp.x = cur.x + dir[i][0];
            tmp.y = cur.y + dir[i][1];
            tmp.z = cur.z + dir[i][2];
            if(judge(tmp.x,tmp.y,tmp.z))
            {
                visit[tmp.x][tmp.y][tmp.z] = 1;
                sum++;
                Q.push(tmp);
            }
        }
    }
        return sum >= t?sum:0;
}

int main(void)
{
    ans = 0;
    scanf("%d %d %d %d",&m,&n,&l,&t);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                scanf("%d",&maze[i][j][k]);

    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(!visit[i][j][k] && maze[i][j][k] == 1)
                {
                    ans += bfs(i,j,k);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0 ;
}
