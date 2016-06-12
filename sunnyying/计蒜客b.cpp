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
using namespace std;
#define N 100100
#define INF 0x7fffffff
#define endl '\n'
#define ll long long
#define mod 1000000007
int a[1010][1010],mark[1010],flag[1010],n,zzz[1010],vis[1010],ans;
struct node{
    int x,i;
}w[100];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
int main()
{
   // freopen("in.in","r",stdin);
 //   freopen("out.out","w",stdout);
    int x,y,z,c;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        a[i][0]=x;
        for(int j=1;j<=x;j++) scanf("%d",&a[i][j]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d%d%d",&x,&y,&z,&c);
        mark[0]=a[x][0];
        for(int i=1;i<=a[x][0];i++) mark[i]=a[x][i];
        a[x][0]=c+a[x][0]-y;
        for(int i=1;i<=c;i++) a[x][i]=a[z][i];
        for(int i=c+1;i<=a[x][0];i++) a[x][i]=mark[i-c+y];
        flag[0]=a[z][0];
        for(int i=1;i<=a[z][0];i++) flag[i]=a[z][i];
        a[z][0]=y+a[z][0]-c;
        for(int i=1;i<=y;i++) a[z][i]=mark[i];
        for(int i=y+1;i<=a[z][0];i++) a[z][i]=flag[i-y+c];
        ans=0;
        for(int i=1;i<=n;i++)
        {
            w[i].x=0;w[i].i=a[i][0];
            for(int j=1;j<=a[i][0];j++) w[i].x=max(w[i].x,a[i][j]-j+1);
        }
        sort(w+1,w+n+1,cmp);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            w[i].x-=sum;
            ans=max(w[i].x,ans);
            sum+=w[i].i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
