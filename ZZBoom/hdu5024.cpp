//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const LL INF=0x3f3f3f3f;

const int N=1e2+7;
char ma[N][N];
int n;

int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};


int Judge(int x,int y)
{
    if(x<0||y<0||x>=n||y>=n||ma[x][y]=='#')
        return 0;
    return 1;
}

int bfs(int i,int j)
{
    int sum[8];
    for(int k=0;k<8;k++)
        sum[k]=1;

    for(int k=0;k<8;k++)
    {
        int aa=i+dx[k];
        int bb=j+dy[k];
        while(Judge(aa,bb)){
            sum[k]++;
            aa+=dx[k];
            bb+=dy[k];
        }
    }

    int ans=0;
//    for(int k1=0;k1<8;k1+=2)
//        for(int k2=1;k2<8;k2+=2)
//            ans=max(ans,sum[k1]+sum[k2]);

    for(int k1=0;k1<8;++k1)
        for(int k2=0;k2<8;++k2)
            if((k1%2==k2%2)&&k1!=k2)    //对于数组的特性，奇数都是斜方向，偶数都是竖直方向。 
                ans=max(ans,sum[k1]+sum[k2]);

    return ans-1;
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(!n) break;
        int i,j,ans;
        for(i=0;i<n;i++)
            scanf("%s",ma[i]);
        ans=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(ma[i][j]=='.')
                    ans=max(ans,bfs(i,j));
        printf("%d\n",ans);
    }
    return 0;
}
