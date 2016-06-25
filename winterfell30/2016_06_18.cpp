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

LL num1[5];
LL num2[5];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    LL n, m;
    cin >> n >> m;
    for (int i = 0 ; i < 5; i++)
    {
        num1 [i] = n / 5;
        if(n % 5 >= i) num1[i]++;
        num2[i] = m / 5;
        if(m % 5 >= i) num2[i]++;
    }
    num1[0]--, num2[0]--;
    LL ans = 0;
    ans = num1[0] * num2[0] + num1[1] * num2[4] + num1[2] * num2[3] + num1[3] * num2[2] + num1[4] * num2[1];
    cout << ans << endl;
    return 0;
}

