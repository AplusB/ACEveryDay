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

int a[200010];

int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        int ans = 0;
        for (int i = 0;i < n ;++ i)
        {
            scanf("%d",&a[i]);
            ans ^= a[i];
        }
        if (!ans)
            puts("No");
        else
        {
            puts("Yes");
            for (int i = 0;i < n ;++ i)
            {
                if ((a[i] ^ ans) < a[i])
                    printf("%d %d\n",a[i],a[i] ^ ans);
            }
        }
    }
    return 0;
}
