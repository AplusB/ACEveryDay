#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=1000+9;
const int inf=2e9+9;

double c[maxn];

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%lf",&c[i]);
        if(n==1)
        {
            printf("%.6f\n",c[1]);
            continue;
        }
        double ans=0;
        for(int i=1;i<=n;i++)
        {
            if(i==1 || i==n)
            {
                ans+=1.0*c[i]/2;
            }
            else
                ans+=1.0*c[i]/3;
        }
        printf("%.6f\n",ans);

    }
    return 0;
}
