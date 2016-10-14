#include <bits/stdc++.h>

using namespace std;
const int maxn=2e6+9;
const int inf=2e9+9;
typedef long long ll;

ll w[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(w,0,sizeof(w));
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            w[x]++;
        }
        for(int i=0;i<maxn;i++)
        {
            w[i+1]+=w[i]/2;
            w[i]%=2;
        }
        ll cnt=0;
        for(int i=0;i<maxn;i++)
            cnt+=w[i];
        printf("%lld\n",cnt);
    }
    return 0;
}

