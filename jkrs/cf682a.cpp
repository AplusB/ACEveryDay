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
#define mk(x,y) make_pair(x,y)
#define pf() pop_front()
#define pb() pop_back()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;

ll a[10],b[10];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < 5; ++ i)
    {
        a[i] = n / 5;
        if (n % 5 >= i)
            ++ a[i];
        b[i] = m / 5;
        if (m % 5 >= i)
            ++ b[i];
    }
    -- a[0];
    -- b[0];
    printf("%I64d\n",a[0] * b[0] + a[1] * b[4] +a[2] * b[3] +a[3] * b[2] + a[4] * b[1]);
    return 0;
}
