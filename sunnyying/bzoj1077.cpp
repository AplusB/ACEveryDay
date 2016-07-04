#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 101
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
typedef long long LL;
#define mod 1000000007
using namespace std;
int pre[N],num[N],m[N][N],r[N],sum[10],mx[N],mi[N],summi[N],summx[N],vis[N][N];
int fi(int x)
{
    if(pre[x]==-1) return x;
    return pre[x]=fi(pre[x]);
}
int main()
{
    int n,a,b;
    char c[100];
    ll ans1=0,ans2=0,ans3=0;
    scanf("%d%d%d",&n,&a,&b);
    memset(m,-1,sizeof(m));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<n;i++)
    {
        scanf("%s",c);
        for(int j=0;j<n;j++)
        {
            if(c[j]=='+') m[i][j]=2,m[j][i]=1;
            else if(c[j]=='-') m[i][j]=1,m[j][i]=2;
            else if(c[j]=='=') m[i][j]=m[j][i]=0;
        }
    }
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                 if(i==j||i==k||j==k||m[i][j]!=-1) continue;
                 if(m[i][k]==-1||m[k][j]==-1) continue;
                 if(m[i][k]==2&&(m[k][j]==2||m[k][j]==0)) m[i][j]=2,m[j][i]=1;
                 if(m[i][k]==1&&(m[k][j]==1||m[k][j]==0)) m[i][j]=1,m[j][i]=2;
                 if(m[i][k]==0&&m[k][j]==2) m[i][j]=2,m[j][i]=1;
                 if(m[i][k]==0&&m[k][j]==1) m[i][j]=1,m[j][i]=2;
                 if(m[i][k]==0&&m[k][j]==0) m[i][j]=m[j][i]=0;
            }
    int da=0,db=0,mxa=0,mxb=0,mia=0,mib=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(m[i][j]==0)
            {
                int xx=fi(i),yy=fi(j);
                if(xx!=yy) pre[yy]=xx;
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
           for(int k=0;k<n;k++)
           {
               if(fi(i)!=i||fi(j)!=j||fi(k)!=k||i==j||i==k||j==k) continue;
               if(m[i][j]==2&&m[j][k]==2) num[i]=3,num[j]=2,num[k]=1;
           }
    for(int i=0;i<n;i++)
    {
        num[i]=num[fi(i)];
        if(num[i]==0)
        {
            mx[i]=3,mi[i]=1;
            for(int j=0;j<n;j++)
            {
                if(i!=j&&m[i][j]==1) mx[i]=2,mi[i]=1;
                if(i!=j&&m[i][j]==2) mx[i]=3,mi[i]=2;
            }
        }
        else mx[i]=mi[i]=num[i];
        if(i==a-1||i==b-1||num[i]==0) continue;
        for(int j=0;j<i;j++)
        {
            if(j==a-1||j==b-1||num[j]==0) continue;
            sum[num[i]+num[j]]++;
        }
    }
     int x=num[a-1]==0?mx[a-1]:num[a-1];
    int y=num[b-1]==0?mx[b-1]:num[b-1];
    int xx=num[a-1]==0?mi[a-1]:num[a-1];
    int yy=num[b-1]==0?mi[b-1]:num[b-1];
    int mark=num[a-1]+num[b-1];
    int mark1=x+y,mark2=xx+yy;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(i==a-1||i==b-1||j==a-1||j==b-1||num[i]==0||num[j]==0||num[a-1]==0||num[b-1]==0) continue;
            if(num[i]+num[j]==num[a-1]+num[b-1]) ans2++,vis[i][j]=vis[j][i]=1;
        }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
           if(i!=j&&i!=a-1&&i!=b-1&&j!=a-1&&j!=b-1&&!vis[i][j])
           {
               int x=num[i]==0?mx[i]:num[i];
               int y=num[j]==0?mx[j]:num[j];
               summx[x+y]++;
               if(x+y<mark2) ans1++,vis[i][j]=vis[j][i]=1;
           }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
           if(i!=j&&i!=a-1&&i!=b-1&&j!=a-1&&j!=b-1&&!vis[i][j])
           {
               int x=num[i]==0?mi[i]:num[i];
               int y=num[j]==0?mi[j]:num[j];
               summi[x+y]++;
               if(x+y>mark1) ans3++,vis[i][j]=vis[j][i]=1;
           }
    for(int i=0;i<n;i++)
    {
        if(i!=a-1&&i!=b-1)
        {
            for(int j=0;j<n;j++)
            {
                if(j==b-1||j==i||j==a-1||vis[i][j]) continue;
                if((mx[j]<=mi[b-1]||m[j][b-1]==0||m[j][b-1]==1)&&m[i][a-1]==1) ans1++,vis[i][j]=vis[j][i]=1;
                if((mi[j]>=mx[b-1]||m[j][b-1]==0||m[j][b-1]==2)&&(m[i][a-1]==2||m[i][a-1]==0&&m[j][b-1]!=0&&mi[j]>mx[b-1])) ans3++,vis[i][j]=vis[j][i]=1;
                if(m[i][a-1]==1&&m[j][b-1]==2&&!num[b-1]||(m[i][a-1]==0||num[i]==num[a-1]&&num[i])&&(m[j][b-1]==0||num[j]==num[b-1]&&num[j])) ans2++,vis[i][j]=vis[j][i]=1;
            }
        }
        if(i!=b-1&&i!=a-1)
        {
            for(int j=0;j<n;j++)
            {
                if(j==a-1||j==i||j==b-1||vis[i][j]) continue;
                if((mx[j]<=mi[a-1]||m[j][a-1]==0||m[j][a-1]==1)&&m[i][b-1]==1) ans1++,vis[i][j]=vis[j][i]=1;
                if((m[j][a-1]==0||mi[j]>=mx[a-1]||m[j][a-1]==2)&&(m[i][b-1]==2||m[i][b-1]==0&&m[j][a-1]!=0&&mi[j]>mx[a-1])) ans3++,vis[i][j]=vis[j][i]=1;
                if(m[i][b-1]==1&&m[j][a-1]==2&&!num[a-1]||(m[i][b-1]==0||num[i]==num[b-1]&&num[i])&&(m[j][a-1]==0||num[j]==num[a-1]&&num[j])) ans2++,vis[i][j]=vis[j][i]=1;
            }
        }
    }
    cout<<ans1<<" "<<ans2<<" "<<ans3<<endl;
    return 0;
}
