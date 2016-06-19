#include<cstdio>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

double w,p[110];

int main()
{
    int t,n,v;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d%d%lf",&n,&v,&w);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf",&p[i]);
        }
        
        sort(p+1,p+n+1);
        int maxv=0;
        double sump=0.0,maxw=0.0;
        for(int i=1;i<=n;i++)
        {
            sump+=p[i];
            if((sump/i)<=w)
            {
                maxv=i*v;
                maxw=sump/i;
            }
            else
            {
                break;
            }
        }
        printf("%d %.2lf\n",maxv,maxw/100);
    }
    return 0;
}
