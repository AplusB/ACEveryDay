#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const double inf=2e15+9;

ll a[maxn],b[maxn],p[maxn],q[maxn];
ll l,r;
int tot;

void egcd(ll a, ll b, ll&d, ll&x, ll&y)
{
    if (!b) { d = a, x = 1, y = 0; }
    else
    {
        egcd(b, a%b, d, y, x);
        y -= x*(a / b);
    }
}

// x=b mod a
ll lmes() {
    ll M = a[0], R = b[0], x, y, d;
    for (int i = 1; i < tot; i++) {
        egcd(M, a[i], d, x, y);
        if ((b[i] - R) % d) return -1;
        x = (b[i] - R) / d*x % (a[i] / d);
        R += x*M;
        M = M / d*a[i];
        R %= M;
    }
    R = (R + M) % M - M;
    ll ans=(r-R)/M-(l-1-R)/M;
    if(tot&1)
        return ans;
    else
        return -ans;
}


int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d%lld%lld",&n,&l,&r);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&p[i],&q[i]);
        }
        
        ll ans=0;
        int up=1<<n;
        for(int i=0;i<up;i++)
        {
            tot=0;
            a[0]=7,b[0]=0;
            tot++;
            int tmp=i;
            for(int j=0;j<n;j++)
            {
                if(tmp&1)
                {
                    a[tot]=p[j],b[tot]=q[j];
                    tot++;
                }
                tmp>>=1;
            }
            ans+=lmes();
        }
        printf("Case #%d: ",cas++);
        printf("%lld\n",ans);


    }
    return 0;
}
