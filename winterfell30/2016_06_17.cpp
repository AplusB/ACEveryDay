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
const int MOD = 1000000007;
const int maxn = 100000 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int flag = 0;
    int a, b, n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%*s %d %d", &a, &b);
        if (a >= 2400 && b > a) flag = 1;
    }
    puts(flag ? "YES" : "NO");
    return 0;
}

