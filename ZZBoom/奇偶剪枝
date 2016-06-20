//hdoj1010

#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<queue>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
using namespace std;
#define INF 0x3f3f3f3f
#define N 10
char ma[N][N];
bool vis[N][N];
int n,m,k;
int ax,ay,bx,by;
int flag;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int a,int b,int num)
{
    if(num==k&&a==bx&&b==by)
    {
        flag=1;
        return;
    }
    if((k-num)%2!=(abs(a-bx)+abs(b-by))%2)
        return;

    if(flag||num>k)
        return;

    for(int i=0;i<4;i++)
    {
        int aa=a+dx[i];
        int bb=b+dy[i];
        if(aa<0||bb<0||aa>=n||bb>=m||ma[aa][bb]=='X')
            continue;
        ma[aa][bb]='X';
        dfs(aa,bb,num+1);
        ma[aa][bb]='.';
    }
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&k)&&n&&m&&k)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%s",ma[i]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]=='.')
                    sum+=1;
                if(ma[i][j]=='S')
                {
                    ax=i;
                    ay=j;
                }
                if(ma[i][j]=='D')
                {
                    bx=i;by=j;
                }
            }
        }
        if(k>sum+1)
        {
            printf("NO\n");
            continue;
        }
        flag=0;
        ma[ax][ay]='X';
        dfs(ax,ay,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
