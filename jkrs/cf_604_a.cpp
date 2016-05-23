#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <iterator>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;

double s[] = {500, 1000, 1500, 2000,2500};

double m[10],w[10];

int main()
{
    for (int i = 0;i < 5; ++ i)
        scanf("%lf",&m[i]);
    for (int i = 0;i < 5; ++ i)
        scanf("%lf",&w[i]);
    double hs,hu;
    scanf("%lf%lf",&hs,&hu);
    double sum = 0;
    for (int i = 0;i < 5; ++ i)
        sum += max(0.3 * s[i],(1.0 - m[i] * 1.0 / 250) * s[i] - 50 * w[i]);
    sum = sum + hs * 100 - hu * 50;
    printf("%.0lf\n",sum);
    return 0;
}
