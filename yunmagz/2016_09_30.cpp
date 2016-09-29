//Bubble Cup 9 - Finals [Online Mirror]
//C - Potions Homework
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL a[100010];
int main()
{
    int n;
    cin>>n;
    LL ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++) (ans+=(a[i]*a[n-i-1]))%=10007;
    cout<<ans<<endl;
    return 0;
}
//E - Paint it really, really dark gray
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int msz = 212345;

struct Edge
{
    int v,next;
};

Edge eg[msz<<1];
bool ned[msz];
int val[msz];
int head[msz];
int tp;

void Add(int u,int v)
{
    eg[tp].v = v;
    eg[tp].next = head[u];
    head[u] = tp++;
}

bool dfs1(int u,int pre)
{
    int v;

    ned[u] = !val[u];
    for(int i = head[u]; i != -1; i = eg[i].next)
    {
        v = eg[i].v;
        if(v == pre) continue;
        if(dfs1(v,u)) ned[u] = 1;
    }

    //printf("%d %d\n",u,ned[u]);
    return ned[u];
}

bool f;

void prt(int u)
{
    if(f) putchar(' ');
    else f = 1;
    printf("%d",u);
}

void dfs2(int u,int pre)
{
    prt(u);

    for(int i = head[u]; i != -1; i = eg[i].next)
    {
        int v = eg[i].v;
        if(v == pre || !ned[v]) continue;

        val[v] ^= 1;
        dfs2(v,u);
        prt(u);
        val[u] ^= 1;
        if(!val[v])
        {
            prt(v);
            prt(u);
            val[v] ^= 1;
            val[u] ^= 1;
        }
    }

    if(u == pre && !val[u])
    {
        int v = eg[head[u]].v;
        prt(v);
        prt(u);
        prt(v);
    }
}

int main()
{
    int n;

    scanf("%d",&n);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%d",&val[i]);
        if(val[i] == -1) val[i] = 0;
    }

    memset(head,-1,sizeof(head));
    tp = 0;

    int u,v;
    for(int i = 1; i < n; ++i)
    {
        scanf("%d%d",&u,&v);
        Add(u,v);
        Add(v,u);
    }

    dfs1(1,1);

    f = 0;
    dfs2(1,1);

    return 0;
}
