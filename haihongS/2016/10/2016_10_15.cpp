#include <bits/stdc++.h>

using namespace std;
const int maxn=2e3+9;
const int inf=2e9+9;
typedef long long ll;

struct II
{
    ll x,y;
}num[maxn];

int cmp(II a,II b);

int main()
{
    int n;
    ll r;
    while(~scanf("%d%lld",&n,&r))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&num[i].x,&num[i].y);
        }
        sort(num,num+n,cmp);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int pos=0;
            ll a[maxn];
            for(int j=i;j<n;j++)
            {
                if(num[j].x>num[i].x+r) break;
                a[pos++]=num[j].y;
            }
            sort(a,a+pos);
            int now=0,last=0,v=a[now],cnt=0;
            while(now<pos)
            {
                while(last<pos && a[last]<=a[now]+r)
                {
                    cnt++;
                    last++;
                }
                ans=max(ans,cnt);
                cnt--;
                now++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

int cmp(II a,II b)
{
    return a.x<b.x;
}










