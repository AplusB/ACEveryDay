#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000100;

typedef long long LL;

struct ty{
    int to, next, w;
}edge[N];
int f[N], head[N], tot;
LL cnt[N];
int n, m, maxn;
void addedge(int x,int y,int z)
{
    edge[tot].to = y;
    edge[tot].w = z;
    edge[tot].next = head[x];
    head[x] = tot++;
}
void dfs(int u, int pre, int x)
{
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v == pre) continue;
        maxn = max(maxn, edge[i].w ^ x);
        cnt[edge[i].w ^ x]++;
        dfs(v, u, x ^ edge[i].w);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        tot = 0;
        memset(head, -1, sizeof(head));
        memset(cnt, 0, sizeof(cnt));

        scanf("%d", &n);
        for(int i = 1; i < n; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }

        maxn = 0;
        dfs(1, 1, 0);
        scanf("%d", &m);
        cnt[0]++;
//        for (int i = 1; i <= maxn;i++)
//            cout << cnt[i] <<' ';
//        cout << endl;
        for(int i = 0; i < m; i++)
        {
            int s;
            scanf("%d", &s);
            LL re = 0;
            for(int j = 0; j <= maxn; j++)
            {
                if((s^j) == j) re += (cnt[j] * (cnt[j] - 1));
                else re += cnt[j] * cnt[s ^ j];
            }
            re /= 2;
            if(s == 0) re += n;
            printf("%I64d\n", re);
        }
    }
    return 0;
}
