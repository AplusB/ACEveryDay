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

char s[100010];

map <char,int> mp;

map <char,int> cur;

int n;



int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    for (int i = 0;i < n; ++ i)
    {
        if (!mp[s[i]])
        ++ mp[s[i]];
    }
    int sum = 0;
    int ans = inf;
    deque <char> q;
    while (!q.empty())
        q.pf();
    int cursum = 0;
//    printf("mid = %d\n",mid);
    for (int i = 0;i < n ;++ i)
    {
        if (!cur[s[i]])
            ++ cursum;
        ++ sum;
        q.push_back(s[i]);
        ++ cur[s[i]];
//        printf("sum = %d size1 = %d size2 = %d s[i] = %c\n",sum,mp.size(),cur.size(),s[i]);
        while (cursum == mp.size())
        {
            ans = min(ans,sum);
//            printf("ans = %d\n",ans);
            char ch = q.front();
            -- cur[ch];
            if (cur[ch] == 0)
                -- cursum;
            -- sum;
            q.pf();
        }
    }
    if (mp.size() == cursum)
        ans = min(ans,sum);
    printf("%d\n",ans);
    return 0;
}
