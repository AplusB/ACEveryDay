//poj2386

#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

#define N 110

int dx[8]={0,0,1,-1,1,-1,-1,1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
char ma[N][N];
int n,m;

int DFS(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int aa=dx[i]+x;
        int bb=dy[i]+y;
        if(aa<0||aa>=n||bb<0||bb>=m||ma[aa][bb]=='.')
            continue;
        ma[aa][bb]='.';
        DFS(aa,bb);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%s",ma[i]);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]=='W')
                {
                    ma[i][j]='.';
                    DFS(i,j);
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
