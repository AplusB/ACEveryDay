#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int n,a[1024],mi,mx;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++) scanf("%d",a+i);
        mi=mx=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>a[mx])
                mx=i;
            if(a[i]<a[mi])
                mi=i;
        }
        int ans;
        //printf("%d %d\n",mi,mx);
        ans=max(abs(mx-mi),abs(n-mx));
        ans=max(ans,abs(1-mx));
        ans=max(ans,abs(n-mi));
        ans=max(ans,abs(1-mi));
        printf("%d\n",ans);
    }
    return 0;
}
