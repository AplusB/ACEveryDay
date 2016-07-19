#include<cstdio>
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
#define N 200000+10
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod  1000000007
#define ll long long
#define eps 1e-10
using namespace std;
int a[300000],pre[300000],b[300000];
int fi(int x)
{
    if(pre[x]==-1) return x;
    return pre[x]=fi(pre[x]);
}
int mark[300000];
int main()
{
    int n;
    scanf("%d",&n);
    memset(pre,-1,sizeof(pre));
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        int x=i,y=a[i];
        int xx=fi(x),yy=fi(y);
        if(xx==yy) b[i]=i;
        else pre[xx]=yy,b[i]=a[i];
    }
    int sum=1,root=-1,ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]==i&&a[i]==i&&root==-1) root=i,mark[0]=i;
        if(b[i]==i&&i!=root)
        {
            ans++;
            mark[sum++]=i;
        }
    }
    if(root==-1)
    {
        b[mark[1]]=mark[1];
        for(int i=2;i<sum;i++) b[mark[i]]=mark[i-1];
    }
    else
    {
      //  cout<<root<<endl;
        for(int i=1;i<sum;i++)
       {
           //cout<<i<<" "<<mark[i]<<endl;
        b[mark[i]]=mark[i-1];
       }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";cout<<endl;
    return 0;
}
