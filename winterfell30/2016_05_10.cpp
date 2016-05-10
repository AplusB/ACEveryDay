#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define LL long long
#define Lowbit(x) ((x)&(-x))
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1|1
#define MP(a, b) make_pair(a, b)
const int INF = 0x3f3f3f3f;
const int maxn = 1e6 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
LL sum[maxn];
bool vis[maxn];
vector<int> prime;

void init()
{
    for (int i = 2; i * i <= maxn; i++) if (!vis[i])
    {
        prime.push_back(i);
        for (int j = i * 2; j <= maxn; j += i)
            vis[j] = 1;
    }
}

int solve(int n)
{
    int res;
    int cnt = 0;
    for (int i = 2; i * i <= n; i++) if (n % i == 0)
    {
        cnt++, res = i;
        while (n % i == 0) n /= i;
        if (cnt > 1) return 1;
    }
    if (n > 1) cnt++;
    if (cnt > 1) return 1;
    else return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int n;
    init();
    sum[2] = 0;
    for (int i = 3; i <= maxn; i++)         //素数为n，一个质因子为p,多个质因子为1
        if (!vis[i]) sum[i] = sum[i-1] + i;
        else sum[i] = sum[i-1] + solve(i);
    while (cin >> n)
    {
        cout << sum[n] << endl;
    }
    return 0;
}
