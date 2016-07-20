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
const double eps = 1e-6;

int len,n,m;

int a[50010];

bool judge(int mid)
{
    int num = 0;
    int sum = 0;
    for (int i = 1;i < n; ++ i)
    {
        sum += a[i] - a[i - 1];
//        printf("sum = %d mid = %d\n",sum,mid);
        if (sum < mid)
        {
            ++ num;
        }
        else
            sum = 0;
    }
    return num <= m;
}

int main()
{

    while (~scanf("%d%d%d",&len,&n,&m))
    {
        a[0] = 0;
        int r = len;
        for (int i = 1;i <= n ;++ i)
            scanf("%d",&a[i]);
        a[n + 1] = len;
        n += 2;
        sort (a,a + n);
//        for (int i = 0;i < n ;++ i)
//            printf("%d%c",b[i],i == n - 1 ? '\n' : ' ');
        int l = 0;
//        for (int i = 0;i < n; ++ i)
//            printf("%d%c",a[i],i == n - 1 ? '\n' : ' ');
        int ans = 0;
        while (r >= l)
        {
            int mid = l + r >> 1;
            if (judge(mid))
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
