#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005];
int maxn,minn,t1=0,t2=0,n;
int main()
{
        scanf("%d",&n);
        scanf("%d",a);
        maxn=minn=a[0];
        for(int i=1;i<n;i++)
        {
                scanf("%d",a+i);
                if(maxn<a[i])
                {
                        t1=i;
                        maxn=a[i];
                }
                if(minn>a[i])
                {
                        t2=i;
                        minn=a[i];
                }
        }
        if(t1>t2) swap(t1,t2);
        printf("%d",max(n-t1-1,t2));
        return 0;
}
