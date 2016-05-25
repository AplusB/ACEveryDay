#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#define INF 32768
#define ll long long
using namespace std;
double a[20000];
int n,sum[20000],mmin[20000],mmax[20000],ans[20000];
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++) scanf("%lf",&a[i]),sum[i]=0;
        for(int i=0;i<n;i++)
        {
           mmin[i]=mmax[i]=0;
           memset(ans,0,sizeof(ans));
           for(int j=i-1;j>=0;j--)
           {
               mmin[j]=mmin[j+1];
               mmax[j]=mmax[j+1];
               if(a[j]<a[i]) mmin[j]++;
               else mmax[j]++;
               if(mmax[j]==mmin[j]) sum[i]++;
               ans[mmin[j]-mmax[j]+8000]++;
           }
           for(int j=i+1;j<n;j++)
           {

               mmin[j]=mmin[j-1];
               mmax[j]=mmax[j-1];
               if(a[j]<a[i]) mmin[j]++;
               else mmax[j]++;
               if(mmax[j]==mmin[j]) sum[i]++;
               sum[i]=sum[i]+ans[8000-(mmin[j]-mmax[j])];
           }
        }
        for(int i=0;i<n-1;i++) printf("%d ",sum[i]+1);
        printf("%d\n",sum[n-1]+1);
    }
    return 0;
}
