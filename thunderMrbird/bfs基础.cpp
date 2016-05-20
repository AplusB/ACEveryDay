#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
#define INF 1000000001
bool vis[100005];
struct node
{
    int x,y;
};
queue<node> que;
int main()
{
    int n,k;
    node t,p;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        t.y=0;
        t.x=n;
        que.push(t);
        vis[n]=1;
    while(!que.empty())
    {
        t=que.front();
        que.pop();
        if(t.x==k) break;
        else
        {
            for(int i=0;i<3;i++)
            {
                if(i==0) p.x=t.x+1;
                else if(i==1)  p.x=t.x-1;
                else if(i==2)  p.x=t.x*2;
                if(p.x>=0&&p.x<=100000&&!vis[p.x])
                {
                    p.y=t.y+1;
                    que.push(p);
                    vis[p.x]=1;
                }
            }
        }
    }
    printf("%d\n",t.y);
    }
    return 0;
}
