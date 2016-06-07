#include<bits/stdc++.h>
using namespace std;
int a[10000+10],c[200000+10];

int main()
{
    int _,n,t,s,ans;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        s=0;
        memset(c,0,sizeof(c));
        ans=n-1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            s+=a[i];
        }
        if(s%n!=0) puts("Impossible");
        else
        {
            s/=n;
            t=0;
            for(int i=1;i<=n;i++)
            {
                a[i]-=s;
                t+=a[i];
                    c[t+100000]++;
                    ans=min(ans,n-c[t+100000]);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
