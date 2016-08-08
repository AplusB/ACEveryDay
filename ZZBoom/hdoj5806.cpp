#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N=2e5+10;
int a[N];
int s,e,cnt;
int n,m,k;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        LL ans=0;
        cnt=e=0;

        for(s=1;s<=n;s++)
        {
            while(cnt<k&&e<=n)
            {
                if(a[++e]>=m)
                    cnt++;
            }
            if(cnt>=k)
                ans+=n-e+1;
            if(a[s]>=m)
                --cnt;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

