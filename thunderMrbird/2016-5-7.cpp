#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100005],b[100005];
int main()
{
     int n;
     ll k;
     scanf("%d %I64d",&n,&k);
     for(int i=0;i<n;i++)
     scanf("%d",a+i);
     for(int i=0;i<n;i++)
     scanf("%d",b+i);
     ll l=0,r=2e9+5;
     ll mid;
     while(l<r)
     {
         ll sum=0;
         mid=(l+r+1)>>1;
         for(int i=0;i<n;i++)
         {
            sum+=max(0LL,mid*a[i]-b[i]);
            if(sum>k) break;
         }
         if(sum<=k)
            l=mid;
         else
            r=mid-1;
     }
     //printf("%I64d %I64d ",r,mid);
     printf("%I64d",l);
     return 0;
}
