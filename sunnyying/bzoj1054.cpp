#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define mod 1000000007
#define ll long long
using namespace std;
int cx[]={0,0,1,-1};
int cy[]={1,-1,0,0};
int cz[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int mark[16][4],t,s,vis[300000],dis[300000];
void init()
{
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
            {
                int xx=i+cx[k],yy=j+cy[k];
                if(xx<0||xx>=4||yy<0||yy>=4) continue;
                mark[i*4+j][k]=cz[xx*4+yy]-cz[i*4+j];
            }
}
char c[10];
int bfs()
{
    queue<int>q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    dis[s]=0;
    if(s==t) return 0;
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=0;i<16;i++)
        {
            if(x&(1<<i))
            {
                for(int j=0;j<4;j++)
                {
                    int xx=x+mark[i][j];
                    if(vis[xx]) continue;
                    q.push(xx);
                    vis[xx]=1;
                    dis[xx]=dis[x]+1;
                    if(xx==t) return dis[xx];
                }
            }
        }
    }
    return 0;
}
int main()
{
    init();
    for(int i=0;i<4;i++)
    {
        scanf("%s",c);
        for(int j=0;j<4;j++) if(c[j]=='1') s+=cz[i*4+j];
    }
    getchar();
    t=0;
    for(int i=0;i<4;i++)
    {
        scanf("%s",c);
        for(int j=0;j<4;j++)
            if(c[j]=='1') t+=cz[i*4+j];
    }
    cout<<bfs()<<endl;
    return 0;
}
