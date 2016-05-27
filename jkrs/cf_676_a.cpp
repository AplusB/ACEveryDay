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
    int minn = inf,minid = 0,maxn = 0,maxid = 0;
    for (int i = 1;i <= n; ++ i)
    {
        int x;
        scanf("%d",&x);
        if (x > maxn)
        {
            maxn = x;
            maxid = i;
        }
        if (x < minn)
        {
            minn = x;
            minid = i;
        }
    }
//    printf("max1 = %d max2 = %d maxid = %d minid = %d\n",max(minid - 1,n - maxid),max(n - minid,maxid - 1),maxid,minid);
    printf("%d\n",max(max(minid - 1,n - maxid),max(n - minid,maxid - 1)));
    return 0;
}
