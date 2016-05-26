#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
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

map <ll,int> m;


int main()
{
    int n;
    scanf("%d",&n);
    ll sum = 0;
    int ans = 0;
    for (int i = 1;i <= n; ++ i)
    {
        ll x;
        scanf("%I64d",&x);
        sum += x;
        ans = max(ans,++ m[sum]);
    }
    printf("%d\n",n - ans);
    return 0;
}
