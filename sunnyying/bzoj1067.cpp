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
int b[100010],a[100010],dp[100010][50],n;
void RMQ_init()
{
    for(int i=1; i<=n; i++) dp[i][0]=b[i];
    for(int j=1; (1<<j)<=n; j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int RMQ(int L,int R)
{
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(dp[L][k],dp[R-(1<<k)+1][k]);
}
map<int,int>A;
int ef(int x,int mark)
{
    int l=1,r=n;
    int ans1=0,ans2=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]<x) l=mid+1,ans1=mid;
        else r=mid-1,ans2=mid;
    }
    if(mark) return ans1;
    return ans2;
}
int main()
{
 //   freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    int x,y,m,xx,yy;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),A[a[i]]=i;
        RMQ_init();
        scanf("%d",&m);
        while(m--)
        {
            int flag=0,mark=0;
            scanf("%d%d",&x,&y);
            if(A[x]==0) xx=ef(x,0),mark=1;
            else xx=A[x];
            if(A[y]==0) yy=ef(y,1),flag=1;
            else yy=A[y];
            if(!flag&&!mark&&b[xx]>=b[yy]&&y>=x&&y-x==yy-xx&&(x+1==y&&b[yy]<b[xx]||RMQ(xx+1,yy-1)<b[yy])) cout<<"true"<<endl;
            else if(flag&&mark&&y>=x) cout<<"maybe"<<endl;
            else if(!mark&&flag&&y>=x&&(xx==yy||RMQ(xx+1,yy)<b[xx])) cout<<"maybe"<<endl;
            else if(mark&&!flag&&y>=x&&(xx==yy||RMQ(xx,yy-1)<b[yy])) cout<<"maybe"<<endl;
            else if(!mark&&!flag&&b[xx]>=b[yy]&&y>=x&&RMQ(xx+1,yy)<b[xx]&&(xx+1==yy||RMQ(xx+1,yy-1)<b[yy])) cout<<"maybe"<<endl;
            else cout<<"false"<<endl;
        }
    }
    return 0;
}
