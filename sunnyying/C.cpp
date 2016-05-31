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
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
    double x,y,c;
    while(~scanf("%lf%lf%lf",&x,&y,&c))
    {
        double l=0,r=min(x,y),mid;
        while(r-l>1e-10)
        {
            mid=(l+r)/2;
            double res=1-c/sqrt(x*x-mid*mid)-c/sqrt(y*y-mid*mid);
            if(res>0) l=mid;
            else r=mid;
        }
        printf("%.3lf\n",mid);
    }
    return 0;
}
