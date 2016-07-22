#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <functional>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#define pu system("pause")
#define ff first
#define ss second
#define clr(x) memset(x,0,sizeof (x))
#define clrs(x) memset(x,-1,sizeof (x))
#define pt(y) push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;



int main()
{
    int t;
    scanf("%d",&t);
    while (t --)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (m >= n)
            puts("first");
        else
        {
            if (n % (m + 1) == 0)
                puts("second");
            else
                puts("first");
        }
    }
    return 0;
}
