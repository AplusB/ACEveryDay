//CF #351 div1 B - Robin Hood
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+100, mod = 1e9 + 7, inf = 0x3f3f3f3f;
int c[MAXN];
int n,k;
int check1(int Max)
{
    int i;
    __int64 kk=0,tt=0;
    for(i=0; i<n; i++)
    {
        if(c[i]>Max)
            kk+=(c[i]-Max);  ///统计比当前答案大得可以拿出多少
        else
            tt+=(Max-c[i]);  ///统计比当前答案小的一共得到多少
    }
    if(kk<=k&&tt>=kk) return 1;///多的数必须小于天数，并且小的必须大于多的，说明答案太大了
    return 0;
}
int check2(int Min)
{
    int i;
    __int64 kk=0,tt=0;
    for(i=0; i<n; i++)
    {
        if(c[i]<Min)
            kk+=(Min-c[i]);  ///比当前答案小的总数
        else
            tt+=(c[i]-Min);  ///比当前答案大的总数
    }
    if(kk<=k&&tt>=kk) return 1; ///小的总数必须小于天数，大的总数大于小的总数，说明当前的答案太小
    return 0;
}
int main()
{
    int i;
    scanf("%d%d",&n,&k);
    for(i=0; i<n; i++)
        scanf("%Id",&c[i]);
    sort(c,c+n);
    int Max=c[n-1],Min=c[0];
    int r=Max,l=Min;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check1(mid))
        {
            r=mid-1;
            Max=mid;
        }
        else l=mid+1;
    }
    r=c[n-1];
    l=c[0];
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check2(mid))
        {
            l=mid+1;
            Min=mid;
        }
        else r=mid-1;
    }
    printf("%d\n",Max-Min);
    return  0;
}
