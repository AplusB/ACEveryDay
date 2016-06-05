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
typedef long long ll;
const int inf = 1e6+1;
int n;
int a[505];
int v[505][505];
bool vis[505];
void floyd()
{
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
     if(v[i][j]>v[i][k]+v[k][j])
   v[i][j]=v[i][k]+v[k][j];
}
int gcd(int a,int b)
{
    if(a==0)
    {
        return b;
    }else
    {
        return gcd(b % a,a);
    }
}
int main()
{
        int x,y,ans=0;
       scanf("%d",&n);
       for(int i=1;i<=n;i++)
        scanf("%d",a+i);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
            v[i][j]=inf;
        memset(vis,0,sizeof(vis));
       for(int i=1;i<n;i++)
       {
               scanf("%d %d",&x,&y);
               v[x][y]=v[y][x]=1;
       }
       floyd();
       for(int i=1;i<=n;i++)
       {
               for(int j=i+1;j<=n;j++)
               {
                        int t1=a[j],t2=a[i];
                        if(t1>t2) swap(t1,t2);
                       if(gcd(t1,t2)==1)
                       {
                         //  printf("%d %d\n",i,j);
                            ans+=v[i][j];
                       // printf("%d\n",ans);
                       }
               }
       }
       printf("%d\n",ans);
    return 0;
}
