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

int n,m;

int a[1010];

vector <int> res;

bool judge(int mid)
{
    int cnt = 1;
    int sum = a[0];
    for (int i = 1;i < n ;++ i)
    {
        sum += a[i];
        if (sum > mid)
        {
//            res.pt(sum - a[i]);
            ++ cnt;
            sum = a[i];
        }
    }
//    res.pt(sum);
//    printf("mid = %d cnt = %d m = %d\n",mid,cnt,m);
    return cnt <= m;
}

int main()
{
//    freopen("out.txt","w",stdout);
    int t,k = 1;
    scanf("%d",&t);
    while (t --)
    {
        scanf("%d%d",&n,&m);
        ++ n;
        ++ m;
        int l = 0,r = 0;
        for (int i = 0;i < n ;++ i)
        {
            scanf("%d",&a[i]);
            l = max(l,a[i]);
            r += a[i];
        }
        printf("Case %d: ",k ++);
        int ans = 0;

        while (r >= l)
        {
            int mid = l + r >> 1;
            if (judge(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        printf("%d\n",ans);
        res.clear();
//        judge(ans);
        int sum = a[0];
        int cnt = 0;
        for (int i = 1;i < n; ++ i)
        {
            if (n - i + cnt + 1 > m)
            {
                if (sum + a[i] > ans)
                {
                    ++ cnt;
                    res.pt(sum);
                    sum = a[i];
                }
                else
                    sum += a[i];
            }
            else
            {
                res.pt(sum);
                sum = a[i];
                ++ cnt;
            }
        }
        res.pt(sum);
//        printf("size = %d\n",res.size());
        for (int i = 0;i < res.size(); ++ i)
            printf("%d\n",res[i]);
    }
    return 0;
}
