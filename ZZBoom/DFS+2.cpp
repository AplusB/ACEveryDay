POJ 3051

#include<cstdio>
#include<vector>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0X3f3f3f3f
typedef long long LL;

#define N 10010

char ma[1010][90];
int n,m;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int sum;

void DFS(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int aa=dx[i]+x;
        int bb=dy[i]+y;
        if(aa<0||bb<0||aa>=n||bb>=m||ma[aa][bb]=='.')
            continue;
        sum++;
        ma[aa][bb]='.';
        DFS(aa,bb);
    }
}

int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
        scanf("%s",ma[i]);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ma[i][j]=='*')
            {
                sum=1;
                ma[i][j]='.';
                DFS(i,j);
                ans=max(ans,sum);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

