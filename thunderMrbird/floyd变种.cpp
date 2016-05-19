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
int mp[301][301];
int n,m,t;
int a,b,c;
void floyd()
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                mp[i][j]=min(mp[i][j],max(mp[i][k],mp[k][j]));
}
void init()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        mp[i][j]=INF;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b]=c;
        }
        floyd();
        for(int i=0;i<t;i++)
        {
            scanf("%d%d",&a,&b);
            if(mp[a][b]<INF)
                printf("%d\n",mp[a][b]);
            else
                printf("-1\n");
        }
    }
    return 0;
}
