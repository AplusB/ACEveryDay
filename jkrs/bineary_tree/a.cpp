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
#define pt(x,y) (x).push_back(y)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const int inf = 0x7fffffff;
const int mod = 1e8;
const double eps = 1e-6;

int tree[100000],od[100000],mid[100000];

void build (int p,int dl,int dr,int ml,int mr)
{
    if (dl > dr || ml > mr)
        return ;
    tree[p] = od[dr];
    int p1 = -1;
    for (int i = ml;i <= mr; ++ i)
    {
        if (tree[p] == mid[i])
        {
            p1 = i;
            break;
        }
    }
    if (p1 == -1)
        return ;
    int p2 = p1 - ml;
//    printf("p1 = %d p2 = %d\n",p1,p2);
    build (p << 1,dl,dl + p2 - 1,ml,p1 - 1);
    build (p << 1 | 1,dl + p2,dr - 1,p1 + 1,mr);

}

queue <int> q;

void bfs()
{
    while (!q.empty())
        q.pop();
    q.push(1);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur != 1)
            printf(" ");
        printf("%d",tree[cur]);
        if (tree[cur << 1])
            q.push(cur << 1);
        if (tree[cur << 1 | 1])
            q.push(cur << 1 | 1);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n; ++ i)
        scanf("%d",&od[i]);
    for (int i = 1;i <= n; ++ i)
        scanf("%d",&mid[i]);
    build (1,1,n,1,n);
    bfs();
    puts("");
    return 0;
}
