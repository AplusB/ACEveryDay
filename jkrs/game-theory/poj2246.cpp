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
typedef pair <int,int> P;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;

int f[35];

void init()
{
    for (int i = 1;i < 30; ++ i)
        f[i] = 1 << i;
}

void cal(int n,int m,int p)
{
    if (n <= 2 * m)
    {
        if (n != p && n % 2 == p % 2)
        {
            puts("1");
            return ;
        }
        else if (n == p)
        {
            printf("%d\n",m - (n - 1) / 2);
            return ;
        }
        else
        {
            puts("0");
            return ;
        }
    }
    else if (n == 2 * m + 1)
    {
        if (p < 2 * m && p & 1)
        {
            puts("1");
            return ;
        }
        else
        {
            puts("0");
            return ;
        }
    }
    else
    {
        int res = n - 2 * m;
        for (int i = 1;i < 30; ++ i)
        {
            if (res == f[i])
            {
                puts("0");
                return ;
            }
        }
        for (int i = 2;i < 30; ++ i)
        {
            if (res < f[i])
            {
                if (p > 2 * m + f[i - 1] && p < 2 * m + f[i])
                {
                    puts("Thrown");
                    return ;
                }
                else
                {
                    puts("0");
                    return ;
                }
            }
        }
    }
}


int main()
{
    int t;
    init();
    scanf("%d",&t);
    while (t --)
    {
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        cal(n,m,p);
    }
    return 0;
}
