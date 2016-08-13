#include<cstdio>
#include<iostream>
#include<queue>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define eps 1e-8
typedef __int64 LL;


const int N=1e5+10;
int a[N];

int t[35];
void init()
{
    for(int i=0;i<31;i++)
        t[i]=1<<i;
}

int main()
{
    init();
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);

    int temp,s,e,mid;
    LL ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<31;j++)
        {
            temp=t[j]-a[i];
            if(temp<1||temp>1e9)
                continue;
            s=lower_bound(a+i+1,a+n,temp)-a;//第一个等于temp的位置；
            e=upper_bound(a+i+1,a+n,temp)-a;//大于temp的位置；
            ans+=e-s;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
