#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int i,j;
        double res=0.0;
        for(i=1;i<n;i+=1)
        {
            double tmp=1.0*i/n*(n+m)*1.0;
            res+=(double)fabs(tmp-floor(tmp+0.5));
        }
        printf("%.4f\n",res*10000/(n+m));
    }
}
