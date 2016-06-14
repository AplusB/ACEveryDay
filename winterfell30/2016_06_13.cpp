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
const int maxn = 1000 + 7;
const double eps = 1e-8;
const double PI = acos(-1.0);
typedef pair<int, int> pii;
struct Edge
{
    int u, v, w;
    bool operator<(const Edge& rhs)const
    {
        return w < rhs.w;
    }
};
vector<Edge> edge;
int fa[110], n;

int find(int x)
{
    return (fa[x] == -1) ? x : (fa[x] = find(fa[x]));
}

int Kruskal()
{
    sort(edge.begin(), edge.end());
    int sum = 0;
    for (int i = 0; i < edge.size(); i++)
    {
        int u = edge[i].u;
        int v = edge[i].v;
        int rta = find(u);
        int rtb = find(v);
        if (rta != rtb)
        {
            fa[rta] = rtb;
            sum += edge[i].w;
        }
    }
    int num = 0;
    for (int i = 1; i <= n; i++)
        if (fa[i] == -1) num++;
    if (num > 1) return -1;
    return sum;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int ncase = 1; ncase <= T; ncase++)
    {
        int x;
        scanf("%d", &n);
        int sum = 0;
        edge.clear();
        for (int i = 0; i <= n; i++)
            fa[i] = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &x);
                sum += x;
                if (x) edge.push_back((Edge){i, j, x});
            }
        }

        printf("Case %d: ", ncase);
        int ans = Kruskal();
        if (ans == -1) sum = -2;
        printf("%d\n", sum - ans);
    }
    return 0;
}

