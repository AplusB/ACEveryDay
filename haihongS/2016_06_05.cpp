#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <stack>

using namespace std;
typedef long long ll;
const int maxn=5e2+9;
const int inf=1e9+9;
const double pi=3.1415926535898;

int main()
{
    double l1,l2,jiao;
    while(~scanf("%lf%lf%lf",&l1,&l2,&jiao))
    {
        jiao/=180.0;
        double l3=sqrt(l1*l1+l2*l2-2*l2*l1*cos(jiao*pi));
        double ans=(l1+l2+l3)/4.0;
        ans=pi*ans*ans;
        printf("%.9f\n",ans);
    }
    return 0;
}
