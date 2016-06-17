#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 1250010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
int S,T,flag;
int ans[][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,-1,1,1},{0,0,0,0,1},{0,0,0,0,0}};
int cx[]={1,1,-1,-1,2,2,-2,-2};
int cy[]={2,-2,2,-2,1,-1,1,-1};
int judge(int a[6][6])
{
    int res=0;
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++) if(a[i][j]!=ans[i][j]) res++;
    return res;
}
void dfs(int t,int a[6][6],int x,int y,int k)
{
    if(!judge(a)) flag=1;
    if(flag) return;
    if(t>=k) return;
    for(int i=0;i<8;i++)
    {
        int xx=cx[i]+x,yy=cy[i]+y;
        if(xx<0||xx>=5||yy<0||yy>=5) continue;
        swap(a[x][y],a[xx][yy]);
        if(judge(a)+t<=k) dfs(t+1,a,xx,yy,k);
        swap(a[x][y],a[xx][yy]);
    }
}
int main()
{
 //   freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    int t;
    char c[10];
    int a[6][6];
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        for(int i=0;i<5;i++)
        {
            scanf("%s",c);
            for(int j=0;j<5;j++)
            {
                if(c[j]=='*') S=i,T=j,a[i][j]=-1;
                else if(c[j]=='1') a[i][j]=1;
                else a[i][j]=0;
            }
        }
        for(int i=0;i<=15;i++)
        {
            dfs(0,a,S,T,i);
            if(flag) {cout<<i<<endl;break;}
        }
        if(!flag) cout<<-1<<endl;
    }
    return 0;
}
