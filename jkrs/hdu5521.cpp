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
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);
const ll inf = 0x7fffffff;
const int mod = 1e8;
const double eps = 1e-6;

struct node
{
    int to;
    int next;
    ll w;
}edge[2000010];

int head[200010];

int tot;

void init()
{
    clrs(head);
    tot = 0;
}

void add(int u,int v,int w)
{
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot ++;
    edge[tot].to = u;
    edge[tot].w = w;
    edge[tot].next = head[v];
    head[v] = tot ++;
}

struct qnode
{
    int v;
    ll c;
    qnode (int x = 0,ll y = 0) : v(x),c(y) {}
    bool operator < (const qnode & a) const
    {
        return c > a.c;
    }
};

ll d1[200010],dn[200010];

bool vis[200010];

priority_queue <qnode> q;

void dijs(int s,ll d[],int n)
{
    clr(vis);
    for (int i = 1;i <= n; ++ i)
        d[i] = inf;
    while (!q.empty())
        q.pop();
    d[s] = 0;
    q.push(qnode(s,0));
    while (!q.empty())
    {
        qnode cur = q.top();
        q.pop();
        int u = cur.v;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u];~i;i = edge[i].next)
        {
            int v = edge[i].to;
            ll c = edge[i].w;
//            printf("u = %d v = %d\n",u,v);
            if (!vis[v] && d[v] > d[u] + c)
            {
                d[v] = d[u] + c;
                q.push(qnode(v,d[v]));
            }
        }
    }
}

vector <int> res;

int main()
{
    int t,k = 1;
    scanf("%d",&t);
    while (t --)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        init();
        int nn = n;
        while (m --)
        {
            ll time;
            int s;
            scanf("%lld%d",&time,&s);
            ++ nn;
            while (s --)
            {
                int x;
                scanf("%d",&x);
                add(x,nn,time);
            }
        }
        printf("Case #%d: ",k ++);
        dijs(1,d1,nn);
        dijs(n,dn,nn);
        ll ans = inf - 10;
        bool flag = 0;
//        for (int i = 1;i <= n ;++ i)
//            cout << "d1[" << i << "] = " << d1[i] << " dn[" <<i << "] = " << dn[i] <<endl;
        for (int i = 1;i <= n; ++ i)
        {
            ll maxn = max(d1[i],dn[i]);
            if (ans > maxn)
                flag = 1;
            ans = min(ans,maxn);
//            printf("maxn = %d ans = %d\n",maxn,ans);
        }
        if (!flag)
            puts("Evil John");
        else
        {
            printf("%lld\n",ans / 2);
            res.clear();
            for (int i = 1;i <= n; ++ i)
            {
                if (max(d1[i],dn[i]) == ans)
                    res.pt(i);
            }
            for (int i = 0;i < res.size(); ++ i)
                printf("%d%c",res[i],i == res.size() - 1 ? '\n' : ' ');
        }
    }
    return 0;
}
