//hdoj 5105

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a)
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

#define N 1010

double a,b,c,d,L,R;
double disc,x1,x2,z;
double max(double a,double b){
    return a>b?a:b;
}

double f(double x){
    if(x>=L && x<=R)
        return fabs(a*x*x*x + b*x*x + c*x + d);
    return -1;
}

int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R)==6)
	{
        if(a!=0)
		{
            disc = b*b-3*a*c;
            if(disc<=0)
			{
                printf("%.2f\n",max(f(L),f(R)));
            }
			else
			{
                x1=(-sqrt(disc)-b)/(3*a);
                x2=(sqrt(disc)-b)/(3*a);
                printf("%.2f\n",max(max(f(L),f(R)),max(f(x1),f(x2))));
            }
        }
		else
		{
            if(b==0)
                printf("%.2f\n",max(f(L),f(R)));
            else
			{
                z = (-c)/(2*b);
                printf("%.2f\n",max(f(L),max(f(R),f(z))));
            }
        }
    }
    return 0;
}

