#include <cstdio>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <math.h>
#include <stdlib.h>
#define N 100001
#define INF 0x3f3f3f3f
#define endl '\n'
#define mod 1000000009
#define ll long long
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.0);
struct point
{
    double x,y;
    point(){}  point(double _x,double _y)  {   x = _x;y = _y;  }
    point operator -(const point &b)const
    {
        return point(x - b.x,y - b.y);
    }  //²æ»ý
    double operator ^(const point &b)const
    {
        return x*b.y - y*b.x;
    }
}p[N];
struct line
{
    point s,e;
}l[N];
int sgn(double x)
{
     if(fabs(x) < eps)return 0;
     if(x < 0)return -1;
     else return 1;
}
bool inter(line l1,line l2)
{
    return
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
    sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
double dis[1100][1100];
int main()
{
    int t;
    double y1,y2,y3,y4,x;
    while(~scanf("%d",&t))
    {
        if(t==-1) break;
        int sum1=0,sum=0;
        p[sum1].x=0,p[sum1++].y=5.0;
        p[sum1].x=10.0,p[sum1++].y=5.0;
        while(t--)
        {
            scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
            l[sum].s.x=x,l[sum].s.y=0.0,l[sum].e.x=x,l[sum++].e.y=y1;
            l[sum].s.x=x,l[sum].s.y=y2,l[sum].e.x=x,l[sum++].e.y=y3;
            l[sum].s.x=x,l[sum].s.y=y4,l[sum].e.x=x,l[sum++].e.y=10.0;
            p[sum1].x=x,p[sum1++].y=y1;
            p[sum1].x=x,p[sum1++].y=y2;
            p[sum1].x=x,p[sum1++].y=y3;
            p[sum1].x=x,p[sum1++].y=y4;
        }
        for(int i=0;i<sum1;i++)
        {
            for(int j=i+1;j<sum1;j++)
            {
                dis[i][j]=dis[j][i]=INF;
                if(fabs(p[i].x-p[j].x)<eps) continue;
                line l1;
                l1.s.x=p[i].x,l1.s.y=p[i].y;
                l1.e.x=p[j].x,l1.e.y=p[j].y;
                int flag=0;
                for(int k=0;k<sum;k++)
                {
                    if(fabs(l[k].s.x-p[i].x)<eps||fabs(l[k].e.x-p[i].x)<eps) continue;
                    if(fabs(l[k].s.x-p[j].x)<eps||fabs(l[k].e.x-p[j].x)<eps) continue;
                    if(inter(l[k],l1)) flag=1;
                }
                if(flag) continue;
                dis[i][j]=dis[j][i]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
            }
        }
        for(int k=0;k<sum1;k++)
            for(int i=0;i<sum1;i++)
                for(int j=0;j<sum1;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        printf("%.2f\n",dis[1][0]);
    }
    return 0;
}

