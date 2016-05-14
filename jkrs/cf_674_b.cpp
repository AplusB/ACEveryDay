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

bool h[30];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    if (n > 26)
        puts("-1");
    else
    {
        int ans = 0;
        for (int i = 0;s[i]; ++ i)
            h[s[i] - 'a'] = 1;
        for (int i = 0;i < 26; ++ i)
            if (h[i])
                ++ ans;
        printf("%d\n",n - ans);
    }
    return 0;
}
