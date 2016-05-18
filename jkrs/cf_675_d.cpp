#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <functional>
#include <queue>
#include <cmath>
#include <set>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#define ff first
#define ss second
#define pu system("pause")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const ll mod = 1e9 + 7;

set <int> st;

map <int,int> l,r;


int main()
{
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    st.insert(x);
    for (int i = 1;i < n; ++ i)
    {
        scanf("%d",&x);
        set <int> :: iterator it = st.lower_bound(x);
        if (it == st.end())
        {
            -- it;
            r[*it] = x;
            printf("%d%c",*it,i == n - 1 ? '\n' : ' ');
        }
        else if (l[*it] == 0)
        {
            l[*it] = x;
            printf("%d%c",*it,i == n - 1 ? '\n' : ' ');
        }
        else
        {
            -- it;
            r[*it] = x;
            printf("%d%c",*it,i == n - 1 ? '\n' : ' ');
        }
        st.insert(x);
    }
    return 0;
}
