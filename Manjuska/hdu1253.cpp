#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<cmath>
using namespace std;
char visit[52][52][52];
char map[52][52][52];
int a,b,c;
struct node
{
    int x;
    int y;
    int z;
    int time;
};
int dir[6][3]={{1,0,0},{-1,0,0},{0,0,1},{0,0,-1},{0,1,0},{0,-1,0}};
int go(int x,int y,int z)
{
    if(0<=x&&x<a&&0<=y&&y<b&&0<=z&&z<c&&map[x][y][z]==0)
    return 1;
    return 0;
}
int bfs(int m)
{
    node st,ed;
    int i;
    queue<node>q;
    st.x=0;
    st.y=0;
    st.z=0;
    st.time=0;
    q.push(st);
    memset(visit,0,sizeof(visit));
    visit[0][0][0]=1;
    while(!q.empty())
    {
        st=q.front();
        q.pop();
        if(st.time>m)
        return -1;
        if(st.x==a-1&&st.y==b-1&&st.z==c-1&&st.time<=m)
        return st.time;
        for(i=0;i<6;i++)
        {
            ed.x=st.x+dir[i][0];
            ed.y=st.y+dir[i][1];
            ed.z=st.z+dir[i][2];
            if(go(ed.x,ed.y,ed.z)&&!visit[ed.x][ed.y][ed.z])
            {
                visit[ed.x][ed.y][ed.z]=1;
                ed.time=st.time+1;
                if(abs(ed.x-a+1)+abs(ed.y-b+1)+abs(ed.z-c+1)+ed.time>m)
                continue;
                q.push(ed);
            }
        }
    }
    return -1;
}
int main()
{
    int i,j,k,t,ans,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&m);
        for(i=0;i<a;i++)
        for(j=0;j<b;j++)
        for(k=0;k<c;k++)
        scanf("%d",&map[i][j][k]);
        ans=bfs(m);
        printf("%d\n",ans);
    }
    return 0;
}
