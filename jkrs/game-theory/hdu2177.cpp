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

map <P,bool> mp;

int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b),(a + b))
    {
        int k = b - a;
        k = k * (sqrt(5.0) + 1) / 2;
        if (k == a)
        {
            puts("0");
        }
        else
        {
            mp.clear();
            puts("1");
            for (int i = 1;i <= a; ++ i)
            {
                a -= i;
                b -= i;
                if ((int)((b - a) * (sqrt (5.0) + 1) / 2) == a)
                    printf("%d %d\n",a,b),mp[make_pair(a,b)] = 1,mp[make_pair(b,a)] = 1;
                a += i;
                b += i;

            }

            for (int i = 1;i <= a; ++ i)
            {
                a -= i;
                if (mp.count(make_pair(a,b)) == 0 && (int)((b - a) * (sqrt (5.0) + 1) / 2) == a)
                    printf("%d %d\n",a,b),mp[make_pair(a,b)] = 1,mp[make_pair(b,a)] = 1;
                a += i;
//                printf("i = %d a = %d b = %d\n",i,a,b);
                b -= i;
                if (mp.count(make_pair(a,b)) == 0 && (int)(abs(b - a) * (sqrt (5.0) + 1) / 2) == min(a,b))
                    printf("%d %d\n",min(a,b),max(a,b)),mp[make_pair(a,b)] = 1,mp[make_pair(b,a)] = 1;
                b += i;
            }

        }
    }
    return 0;
}
