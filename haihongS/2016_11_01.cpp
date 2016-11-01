#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=50209;
const ll inf=2e14+9;

double  a[maxn];
double pre[maxn],ff[maxn];
int qq;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        if(n==1||n==k)
        {
            printf("0\n");
            continue;
        }
        sort(a+1,a+1+n);
        pre[0]=0,ff[0]=0;
        for(int i=1;i<=n;i++)
        {
            pre[i]=pre[i-1]+a[i];
            ff[i]=ff[i-1]+a[i]*a[i];
        }
        double ans=inf;
        for(int i=1;i+n-k-1<=n;i++)
        {
            int lt=i,rt=i+n-k-1;
            double x0=pre[rt]-pre[lt-1];
            x0=x0/(n-k);
            double now=0;
            now=ff[rt]-ff[lt-1];
            now=now+1.0*(n-k)*x0*x0;
            now-=2.0*(pre[rt]-pre[lt-1])*x0;
            ans=min(ans,now);
        }
        printf("%.11lf\n",ans);
    }
    return 0;
}
