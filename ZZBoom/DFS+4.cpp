//POJ 1562

#include<cstdio>
#include<math.h>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0X3f3f3f3f
typedef long long LL;

#define N 110
int n,m;
char ma[N][N];

int dx[8]={0,0,-1,1,-1,-1,1,1};
int dy[8]={1,-1,0,0,-1,1,-1,1};

void DFS(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int aa=x+dx[i];
        int bb=y+dy[i];
        if(aa<0||bb<0||aa>=n||bb>=m||ma[aa][bb]=='*')
            continue;
        ma[aa][bb]='*';
        DFS(aa,bb);
    }
}


int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(!m)
            break;
        for(int i=0;i<n;i++)
            scanf("%s",ma[i]);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]=='@')
                {
                    ma[i][j]='.';
                    sum++;
                    DFS(i,j);
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}









