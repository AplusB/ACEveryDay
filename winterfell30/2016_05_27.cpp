#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int Mod = 1000000007;
const int maxn = 1e5 + 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
const int d[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
char s[1010][1010];
bool c[1010][1010][4];
int dis[1010][1010][4];
struct node{
    int x,y,d;
    node(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
};
void bfs(int sx,int sy,int n,int m)
{
    memset(dis,INF,sizeof(dis));
    queue<node>q;
    dis[sx][sy][0]=0;
    q.push(node(sx,sy,0));
    while(!q.empty())
    {
        node p=q.front();
        q.pop();
        if(dis[p.x][p.y][(p.d+1)%4]>dis[p.x][p.y][p.d]+1)
        {
            dis[p.x][p.y][(p.d+1)%4]=dis[p.x][p.y][p.d]+1;
            q.push(node(p.x,p.y,(p.d+1)%4));
        }
        for(int i=0;i<4;i++)
        {
            int tx=p.x+d[i][0];
            int ty=p.y+d[i][1];
            if(tx>=0 && tx<n && ty>=0 && ty<m && c[p.x][p.y][(i+p.d)%4] && c[tx][ty][(i+p.d+2)%4])
                if(dis[tx][ty][p.d]>dis[p.x][p.y][p.d]+1)
                {
                    dis[tx][ty][p.d]=dis[p.x][p.y][p.d]+1;
                    q.push(node(tx,ty,p.d));
                }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            char t=s[i][j];
            if(t=='+'||t=='-'||t=='>'||t=='U'||t=='L'||t=='D')c[i][j][0]=1;
            if(t=='+'||t=='|'||t=='^'||t=='R'||t=='L'||t=='D')c[i][j][1]=1;
            if(t=='+'||t=='-'||t=='<'||t=='R'||t=='U'||t=='D')c[i][j][2]=1;
            if(t=='+'||t=='|'||t=='v'||t=='R'||t=='U'||t=='L')c[i][j][3]=1;
        }
    int st[2],ed[2];
    for(int i=0;i<2;i++){
        cin>>st[i];
        st[i]--;
    }
    for(int i=0;i<2;i++){
        cin>>ed[i];
        ed[i]--;
    }
    bfs(st[0],st[1],n,m);
    int res=INF;
    for(int i=0;i<4;i++)
        res=min(res,dis[ed[0]][ed[1]][i]);
    cout<<(res==INF?-1:res)<<endl;
    return 0;
}
