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


int main()
{
    int t,s,x;
    scanf("%d%d%d",&t,&s,&x);
    int n = x - t;
    if (n < 0)
        puts("NO");
    else if (n == 0)
        puts("YES");
    else
    {
        if ((n >= s && n % s == 0) || ((n - 1) >= s && (n - 1) % s == 0))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
