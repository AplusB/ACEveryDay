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
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll inf = 0x7fffffff;
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;

char s[100010];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s + 1);
    int sum = 0;
    for (int i = 1;i <= n; ++ i)
        if (s[i] != s[i - 1])
            ++ sum;
    printf("%d\n",min(sum + 2,n));
    return 0;
}
