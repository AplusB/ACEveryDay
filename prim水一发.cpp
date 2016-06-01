#include<iostream>
#include <stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <string.h>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
const int inf=0x3f3f3f3f;
int mp[50][50];
int dis[50];
char u,v;
int n,m,x,ans;
void init()
{
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                mp[i][j]=inf;
        ans=0;
}
void prim()
{
        for(int i=0;i<=n;i++)
                dis[i]=inf;
        int now=1,t;
        int minn=inf;
        for(int i=1;i<n;i++)
        {
                dis[now]=-1;
                minn=inf;
                for(int j=1;j<=n;j++)
                {
                        dis[j]=min(dis[j],mp[now][j]);
                       if(dis[j]!=-1&&dis[j]<minn)
                       {
                               minn=dis[j];
                               t=j;
                       }
                }
                ans+=minn;
                now=t;
        }
}
int main()
{
        while(scanf("%d",&n)!=EOF&&n)
        {
                init();
                for(int i=1;i<n;i++)
                {
                cin>>u>>m;
                        while(m--)
                        {
                        cin>>v>>x;
                        mp[v-'A'+1][u-'A'+1]=mp[u-'A'+1][v-'A'+1]=x;
                        }
                }
                prim();
                printf("%d\n",ans);
        }

        return 0;
}
