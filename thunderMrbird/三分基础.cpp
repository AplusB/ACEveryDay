#include<iostream>
#include <stdio.h>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <string.h>
#include<queue>
#include<vector>
#include<cmath>
#define M 50007
using namespace std;
double x[M],w[M];
int n;
double calc(double a)
{
    double ans=0;
    for(int i=0;i<n;i++)
    {
        double dis=a-x[i];
        if(dis<0)dis=-dis;
        ans+=dis*dis*dis*w[i];
    }
    return ans;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&x[i],&w[i]);
        double l=x[0],r=x[n-1],mid,midmid,mid_area,midmid_area;
        while(r-l>1e-9)
        {
            mid=(l+r)/2;
            midmid=(mid+r)/2;
            mid_area=calc(mid);
            midmid_area=calc(midmid);
            if(mid_area<midmid_area)r=midmid;
            else l=mid;
        }
        double ans1=calc(l);
        double ans2=calc(r);
        ans1=ans1<ans2?ans1:ans2;
        printf("Case #%d: %.lf\n",cas++,ans1);
    }
    return 0;
}
