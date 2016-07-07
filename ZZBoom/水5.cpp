//hdoj 1173

#include<cstdio>
#include<string.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

double x[1000002],y[1000002];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
       for(int i=0;i<n;i++)
       scanf("%lf%lf",&x[i],&y[i]);
       
       sort(x,x+n);
       sort(y,y+n);
       
       printf("%.2lf %.2f\n",x[n/2],y[n/2]);
    }
    return 0;
}

