#include<bits/stdc++.h>
using namespace std;
struct node
{
    int n;
    double a;
}a[2024],b[2024];
int u[2024];
double ans[2024];
int main()
{
    int n,m,k;
    scanf("%d",&n);
    memset(ans,0,sizeof(ans));
    memset(u,0,sizeof(u));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].n);
        scanf("%lf",&a[i].a);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i].n);
        scanf("%lf",&b[i].a);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int q=a[i].n+b[j].n;
            u[q]=1;
            ans[q]+=b[j].a*a[i].a;
        }
    }
    cnt=0;
    for(int i=2000;i>=0;i--)
    {
        if(u[i]&&ans[i]!=0)
            cnt++;
        else u[i]=0;
    }
    printf("%d",cnt);
    for(int i=2000;i>=0;i--)
    {
        if(u[i]) printf(" %d %.1f",i,ans[i]);
    }
    puts("");
    return 0;
}
