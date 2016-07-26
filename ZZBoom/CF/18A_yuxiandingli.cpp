//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-9;
const double pi=acos(-1.0);
const int mod=1e8+7;

const int INF=25000;

double dx[4]={0,0,-1,1};
double dy[4]={1,-1,0,0};

bool kill(double x1,double x2,double x3,double y1,double y2,double y3)
{
    double ca,cc,cb;
    double a,b,c;
    a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    c=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    if(fabs(a)<eps||fabs(b)<0||fabs(c)<0)
        return 0;
    ca=(b*b+c*c-a*a)/b/c*0.5;
    cb=(c*c+a*a-b*b)/c/a*0.5;
    cc=(a*a+b*b-c*c)/a/b*0.5;
    //printf("%lf\n%lf\n%lf\n",ca,cb,cc);
    if(fabs(ca)<eps||fabs(cb)<eps||fabs(cc)<eps)
        return 1;
    return 0;
}

int main()
{
    double x1,x2,x3,y1,y2,y3;
    double x[5],y[5];
    double xx[5],yy[6];
    for(int i=0;i<3;i++)
        cin>>x[i]>>y[i];
    if(kill(x[0],x[1],x[2],y[0],y[1],y[2])){
        puts("RIGHT");
        return 0;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            int num=0;
            xx[num]=x[i]+dx[j];
            yy[num++]=y[i]+dy[j];
            for(int k=0;k<3;k++){
                if(i!=k){
                    xx[num]=x[k];
                    yy[num++]=y[k];
                }
            }
            if(kill(xx[0],xx[1],xx[2],yy[0],yy[1],yy[2])){
                puts("ALMOST");
                return 0;
            }
        }
    }


    puts("NEITHER");
    return 0;
}
