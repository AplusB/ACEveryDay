#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 250010
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define mod 1000000007
using namespace std;
int a[N],b[N],aa[N],bb[N],aaa[N],bbb[N],n;
int mmin,mmax,mmmin,mmmax;
void getm(int x[N],int y[N],int sum)
{
    mmin=INF,mmax=-INF,mmmin=INF,mmmax=-INF;
    for(int i=0;i<sum;i++)
    {
        mmin=min(mmin,x[i]);
        mmmin=min(mmmin,y[i]);
        mmax=max(mmax,x[i]);
        mmmax=max(mmmax,y[i]);
    }
}
int setzz(int x,int y,int xx,int yy,int sum,int z)
{
    int res=0;
    for(int i=0;i<sum;i++)
    {
        if(aa[i]>=x&&aa[i]<=xx&&bb[i]>=yy&&bb[i]<=y) continue;
        aaa[res]=aa[i],bbb[res++]=bb[i];
    }
    getm(aaa,bbb,res);
    if(max(mmax-mmin,mmmax-mmmin)<=z) return 1;
    return 0;
}
int setz(int x,int y,int xx,int yy,int z)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=x&&a[i]<=xx&&b[i]>=yy&&b[i]<=y) continue;
        aa[sum]=a[i],bb[sum++]=b[i];
    }
    getm(aa,bb,sum);
    int mx=mmax,mi=mmin,mmx=mmmax,mmi=mmmin,ans=0;
    if(max(mx-mi,mmx-mmi)<=z) return 1;
    ans+=setzz(mi,mmx,mi+z,mmx-z,sum,z);
    ans+=setzz(mi,mmi+z,mi+z,mmi,sum,z);
    ans+=setzz(mx-z,mmi+z,mx,mmi,sum,z);
    ans+=setzz(mx-z,mmx,mx,mmx-z,sum,z);
    return ans;
}
int judge(int x)
{
     int ans=0;
     getm(a,b,n);
     int mx=mmax,mi=mmin,mmx=mmmax,mmi=mmmin;
     if(max(mx-mi,mmx-mmi)<=x) return 1;
     ans+=setz(mi,mmx,mi+x,mmx-x,x);
     ans+=setz(mi,mmi+x,mi+x,mmi,x);
     ans+=setz(mx-x,mmi+x,mx,mmi,x);
     ans+=setz(mx-x,mmx,mx,mmx-x,x);
     return ans;
}
int main()
{
   // freopen("in.in","r",stdin);
   // freopen("out.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
    int l=1,r=200000000,ans=r;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    if(n==0) ans=0;cout<<ans<<endl;
    return 0;
}
