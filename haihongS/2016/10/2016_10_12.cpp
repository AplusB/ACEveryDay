#include <bits/stdc++.h>

using namespace std;
const int maxn=2e5+9;
const int inf=2e9+9;
typedef long long ll;
int a[maxn],b[maxn];
int lt[maxn],rt[maxn];

void pre(int n);
int deal(int u,int v);

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<n;i++)
            b[i]=abs(a[i+1]-a[i]);
        pre(n);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            deal(u,v-1);
        }
    }
    return 0;
}

int deal(int u,int v)
{
    ll ans=0;
    for(int i=u;i<=v;i++)
    {
        ll x1=(ll)(i-max(u,lt[i])+1);
        ll x2=(ll)(min(v,rt[i])-i+1);
        //printf("*%d %lld %lld %lld\n",i,x1,x2,x1*x2*(ll)b[i]);
        ans+=x1*x2*(ll)b[i];
    }
    printf("%lld\n",ans);
}

void pre(int n)
{
    int top=0;
    int aha[maxn];
    for(int i=1;i<n;i++)
    {
        while(top!=0 && b[i]>b[aha[top]])
        {
            top--;
        }
        if(top==0) lt[i]=1;
        else lt[i]=aha[top]+1;
        aha[++top]=i;
    }

    top=0;
    for(int i=n-1;i>=1;i--)
    {
        while(top!=0 && b[i]>=b[aha[top]])  top--;
        if(top==0) rt[i]=n-1;
        else rt[i]=aha[top]-1;
        aha[++top]=i;
    }
}
