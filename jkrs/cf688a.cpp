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
#define mk(x,y) make_pair(x,y)
#define pf() pop_front()
#define pb() pop_back()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;
const double eps = 1e-8;

char s[110][110];

int main()
{
    int ans = 0;
    int sum = 0;
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < m ;++ i)
    {
        bool flag = 0;
        scanf("%s",s[i]);
        for (int j = 0;s[i][j]; ++ j)
        {
            if (s[i][j] == '0')
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            ++ sum;
        else
        {
            ans = max(ans,sum);
            sum = 0;
        }
    }
    ans = max(ans,sum);
    printf("%d\n",ans);


    return 0;
}
