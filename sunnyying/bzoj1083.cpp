#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define mod 1000000007
#define ll long long
using namespace std;
int n,m,pre[500],sum[500];
int fi(int x)
{
    if(pre[x]==-1) return x;
    return pre[x]=fi(pre[x]);
}
struct node
{
    int u,v,c;
}a[1000000];
bool cmp(node a,node b)
{
    return a.c<b.c;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
    sort(a,a+m,cmp);
    for(int i=1;i<=n;i++) pre[i]=-1,sum[i]=1;
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int u=a[i].u,v=a[i].v,c=a[i].c;
        int xx=fi(u),yy=fi(v);
        if(xx==yy) continue;
        pre[xx]=yy;
        sum[yy]+=sum[xx];
        ans++;
        if(sum[yy]==n)
        {
            cout<<ans<<" "<<c<<endl;
            break;
        }
    }
    return 0;
}
