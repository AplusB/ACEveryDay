#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn=1e5+6;
double ax,ay,bx,by,tx,ty;
struct node
{
    double x,y;
    double dis1,dis2,dis3;
    int id;
}p[maxn],p1[maxn],p2[maxn];
int n;
double dis(double x,double y,double x1,double y1)
{
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
bool cmp1(node a,node b)
{
    return a.dis1-a.dis3<b.dis1-b.dis3;
}
bool cmp2(node a,node b)
{
    return a.dis2-a.dis3<b.dis2-b.dis3;
}
int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty))
    {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y),p[i].id=i;
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        p[i].dis1=dis(p[i].x,p[i].y,ax,ay);
        p[i].dis2=dis(p[i].x,p[i].y,bx,by);
        p[i].dis3=dis(p[i].x,p[i].y,tx,ty);
        ans+=p[i].dis3;
    }
    ans*=2;
    ans=1e18;
    for(int i=1;i<=n;i++)p1[i]=p[i],p2[i]=p[i];
    sort(p1+1,p1+1+n,cmp1);
    sort(p2+1,p2+1+n,cmp2);
    for(int i=1;i<=100&&i<=n;i++)
    {
        for(int j=1;j<=100&&j<=n;j++)
        {
            if(p1[i].id==p2[j].id)continue;
            double ans2=ans,ans3=ans,ans4=ans,ans5=ans;
            ans2=ans2+p1[i].dis1-p1[i].dis3+p2[j].dis2-p2[j].dis3;
            ans3=ans3+p1[j].dis1-p1[j].dis3+p2[i].dis2-p2[i].dis3;
            ans4=ans4+p1[i].dis1-p1[i].dis3;
            ans5=ans5+p2[j].dis2-p2[j].dis3;
            ans=min(ans,ans2);
            ans=min(ans,ans3);
            ans=min(ans,ans4);
            ans=min(ans,ans5);
        }
        double ans4=ans,ans5=ans;
        ans4=ans4+p1[i].dis1-p1[i].dis3;
        ans5=ans5+p2[i].dis2-p2[i].dis3;
        ans=min(ans,ans4);
        ans=min(ans,ans5);
    }
    printf("%lf\n",ans);
    }
}
