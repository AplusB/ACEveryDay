#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int INF=0x3f3f3f3f;

int dir_x[4]={1,-1,0,0};
int dir_y[4]={0,0,1,-1};

struct node
{
    int x,y;
    int t;
};

char map[15][15];
int vis[15][15];

int n,m;
int tot;//记录草方格的个数
int ans;
int run;//记录跑过的路程
bool flag=false;

queue<node> q[2];//记录分别燃烧的草地，滚动处理
node NA[120];//记录每个草方格的坐标及其步骤

bool inside(node a)
{
    if(a.x>=0&&a.x<n&&a.y>=0&&a.y<m)
		return true;
    return false;
}

void bfs(int k,int sum)//k是小孩编号，sum是以燃烧草方格个数
{
    if(sum==tot)
		flag=true;

    node u,v;
    int sin=0;//记录燃烧的草方格个数

    //由于出对元素的相邻状态入队时，是进入的另一个队列
    //因此，每清空一次处理了向外扩展一层
    while(!q[k].empty())
    {
        v=q[k].front();
        q[k].pop();

        for(int i=0;i<4;i++)
        {
            u=v;//状态转移的方法
            u.x+=dir_x[i];
            u.y+=dir_y[i];
            u.t+=1;

            if(inside(u) && map[u.x][u.y]=='#' && vis[u.x][u.y]==0)
            {
                vis[u.x][u.y]=1;
                sin++;
                run=max(run,u.t);//找出所需最大步数
                q[!k].push(u);//一次的终点作为下下次的起点
            }
        }
    }

    if(sum+sin==tot)
		flag=true;

    if(!q[!k].empty())
        bfs(!k,sum+sin);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);

        memset(map,0,sizeof(map));
        memset(NA,0,sizeof(NA));
        memset(vis,0,sizeof(vis));

        ans=INF;
        tot=0;
        run=0;
        while(!q[0].empty()) q[0].pop();
        while(!q[1].empty()) q[1].pop();

        for(int i=0;i<n;i++)
			scanf("%s",map[i]);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='#')
                {
                    NA[tot++]=(node){i,j,0};//struct类型的强制类型转换与赋值
                }
            }
        }

        if(tot<=2)
			ans=0;
        else
        {
            for(int i=0;i<tot;i++)
            {
                for(int j=i+1;j<tot;j++)
                {
                	//放入两个起点
                    q[0].push(NA[i]);
					q[1].push(NA[j]);
                    memset(vis,0,sizeof(vis));

                    run=0;
                    flag=false;
                    vis[NA[i].x][NA[i].y]=vis[NA[j].x][NA[j].y]=1;//分别选中起点

                    bfs(0,2);//bfs(1,2)是一样的

                    if(flag&&ans>run)
						ans=run;
                }
            }
        }

        if(ans==INF)
			ans=-1;
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}
