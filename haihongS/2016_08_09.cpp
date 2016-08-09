#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2e4+100;
const ll MOD=110119;

struct II
{
    ll x,y;
}bb[200];

ll dp[200],f[MOD+10],all[MOD+10];

ll Lucas(ll n, ll m);
ll C(ll n, ll m);
void init();
int cmp(II a,II b);

int main()
{
    init();
    ll n,m;
    int r;
    int cas=1;
    while(~scanf("%lld%lld%d",&n,&m,&r))
    {
        int index=0;
        for(int i=0;i<r;i++)
        {
            ll x,y;
            scanf("%lld%lld",&x,&y);
            if((x+y+1)%3!=0) continue;
            ll tmp=(x+y+1)/3;
            if(!(tmp<=x && x<=2*tmp-1)) continue;
            bb[index].x=x,bb[index].y=y;
            index++;
            if(x==n && y==m)
            {
                index=-1;break;
            }
        }
        printf("Case #%d: ",cas++);
        if(index==-1 || (n+m+1)%3!=0)
        {
            printf("0\n");continue;
        }
        ll ss=(n+m+1)/3;
        if(!(ss<=n && n<=2*ss-1))
        {
            printf("0\n");continue;
        }
        memset(dp,0,sizeof(dp));
        bb[index].x=n,bb[index].y=m;
        index++;
        sort(bb,bb+index,cmp);
        ll tx=bb[0].x,ty=bb[0].y;
        dp[0]=Lucas(((tx+ty+1)/3-1),tx-(tx+ty+1)/3);
        for(int i=1;i<index;i++)
        {
            ll x=bb[i].x,y=bb[i].y;
            dp[i]=Lucas(((x+y+1)/3-1),x-(x+y+1)/3);
            for(int j=0;j<i;j++)
            {
                tx=bb[j].x,ty=bb[j].y;
                tx=x-tx+1,ty=y-ty+1;
                if((tx+ty+1)%3!=0) continue;
                ll tmp=(tx+ty+1)/3;
                if(!(tmp<=tx && tx<=2*tmp-1)) continue;
                dp[i]-=dp[j]*Lucas(((tx+ty+1)/3-1),tx-(tx+ty+1)/3);
                dp[i]=(dp[i]%MOD+MOD)%MOD;
            }
        }
        /*
        printf("\n");
        for(int i=0;i<index;i++)
        {
            printf("%d %lld\n",i,dp[i]);
        }
        */
        printf("%lld\n",dp[index-1]);
    }
    return 0;
}

ll C(ll n, ll m)
{
    if(m > n) return 0;
    if (m==0) return 1;
    if (m<0) return 0;
    return f[n]*all[f[m]]%MOD*all[f[n-m]]%MOD;
}

ll Lucas(ll n, ll m)
{
    if(m == 0) return 1;
    return C(n % MOD, m % MOD) * Lucas(n / MOD, m / MOD) % MOD;
}

void init()
{
    f[1]=f[0]=all[1]=1;
    for(int i=2; i<=MOD; ++i)
        f[i]=f[i-1]*i%MOD,all[i]=all[MOD%i]*(MOD-MOD/i)%MOD;
}

int cmp(II a,II b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
