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
const ll mod = 998244353;

priority_queue <int,vector <int> ,greater <int> > pq;

int ans[510];

vector <int> a[510];

int fro[510];

int k;

void toposort()
{
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        for (int i = 0;i < a[cur].size(); ++ i)
        {
            int v = a[cur][i];
            -- fro[v];
            if (!fro[v])
                pq.push(v);
        }
        ans[k ++] = cur;
    }
}

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m))
    {
        memset(a,0,sizeof (a));
        memset(fro,0,sizeof (fro));
        while (m --)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            ++ fro[y];
        }
        k = 0;
        for (int i = 1;i <= n; ++ i)
            if (!fro[i])
                pq.push(i);
        toposort();
        for (int i = 0;i < k; ++ i)
            printf("%d%c",ans[i],i == k - 1 ? '\n' : ' ');
    }
    return 0;
}
