#include<bits/stdc++.h>
using namespace std;

int sum[100000+10],a[100000+10];

int main()
{
    int n,m,u,v;
    scanf("%d",&n);
    sum[1]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        sum[i+1]=a[i]+sum[i];
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        if(u>v) swap(u,v);
        int ans=min(sum[v]-sum[u],sum[u]+sum[n+1]-sum[v]);
        printf("%d\n",ans);
    }
    return 0;
}
