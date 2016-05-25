#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <string>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll inf = 0x7fffffff;
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
ll a[100010];
int cnt[50];
int firstone(long long n)
{
    int last = 0;
//    cout << "n = " << n  << endl;
    for (int i = 0; i < 33; ++i)
    {
        if (n & (((ll)1) << i))
        {
//            cout << " i = " << i << endl;

            last = i;
        }
    }
    return last;
}
int main()
{
    int t;
//    cout << firstone(1) << endl;
//    cout << firstone(8) << endl;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i)
        {
//            cout << "i = " << i << endl;
            scanf("%lld", &a[i]);
            int first = firstone(a[i]);
            cnt[first] += 1;

//            cout << "a[i] = " << a[i] << " first = " << first << endl;
//            cout << "**cnt[" << first << "] = " << cnt[first] << endl;
        }
        ll ans = 0;
//        for (int i = 0; i < 5; ++i)
//            cout << "cnt " << i << " = " << cnt[i] << endl;
        for (int i = 0; i < n; ++i)
        {
            int firstbit = firstone(a[i]);
//            cout << "a[i] = " << a[i] << " first = " << firstbit << endl;
            for (int j = firstbit - 1; j >= 0; --j)
            {
                if ((a[i] & (((ll)1) << j)) == 0)
                {
                    ans = ans + cnt[j];
//                    cout << " i = " << a[i] << endl;
                }

            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
