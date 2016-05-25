#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct ty
{
    double a, b, c;
}num[10010];

int n, k;

inline bool comp(ty x,ty y)
{
    return x.c > y.c;
}

bool judge(double x)
{
    for(int i = 1; i <= n; i++)
        num[i].c = num[i].a - num[i].b * x;
    sort(num+1, num+1+n, comp);
    //cout<<x<<endl ;
    double re = 0.0;
    for(int i = 1; i <= n-k; i++)
    {

        re += num[i].c;
    }
    if(re < 0.0) return true;
    else return false;
}

int main()
{
    while(scanf("%d%d",&n, &k)!= EOF && n + k != 0)

    {
        for(int i = 1; i <= n; i++)
            scanf("%lf", &num[i].a);
        for(int i = 1; i <= n; i++)
            scanf("%lf", &num[i].b);
        double l = 0.0, r = 1.0 , mid;
        while(r - l > 1e-5)
        {
            mid = (l + r) / 2.0;
            if(judge(mid)) r = mid;
            else l = mid;
        }
        printf("%.0f\n", mid * 100);
    }
    return 0;
}
