#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,sum,maxn=0,a[500005];
int main()
{
    scanf("%I64d %I64d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",a+i);
        sum+=a[i];
        maxn=max(a[i],maxn);
    }
    if(sum/maxn==n&&sum%maxn==0)
    { 
        printf("0");
        return 0;
    }
    ll l=1,r=1e9+1,ansl=1;
    while (l<r)
    {
		int mid=l+r>>1;
		long long tot=0;
		for (int i=0;i<n;i++)
			if (mid>=a[i]) tot+=mid-a[i];
		if (tot>k) r=mid;
		else
        {
			l=mid+1;
            ansl=mid;
        }
	}
	l=ansl,r=1e9+1;
	ll ansr=r;
	while(l<r)
    {
        int mid=l+r>>1;
        ll tot=0;
        for(int i=0;i<n;i++)
            if(mid<=a[i]) tot+=a[i]-mid;
        if(tot>k) l=mid+1;
        else
        {
            ansr=mid;
            r=mid;
        }
    }
    //printf("%I64d %I64d %I64d %I64d\n",ansl,ansr,sum);
    if (ansl==ansr&&sum%n) ansr++;
    printf("%I64d",ansr-ansl);
    return 0;
}
