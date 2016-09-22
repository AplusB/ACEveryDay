//2016 ACM/ICPC Asia Regional Shenyang Online
//1002	List wants to travel
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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int MAXM = 100050;
const int MAXN = 100050;

struct node
{
    int num,l,r,add;
    node() {}
    node(int c)
    {
        num = 1;
        l = r = c;
        add = -1;
    }
    node operator +(const node & b) const
    {
        node tmp;
        if(!num)
        {
            return b;
        }
        if(!b.num)
            return *this;
        tmp.num = num + b.num;
        tmp.l = l;
        tmp.r = b.r;
        if(r == b.l)
            tmp.num--;
        return tmp;
    }
} sum[MAXN<<2];
int sz[MAXN],son[MAXN],fa[MAXN];
int dep[MAXN],top[MAXN],w[MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int val[MAXN];
int nnum;
struct edge
{
    int v,next;
} e[MAXM];
int pre[MAXN],ecnt;

void pushu(int rt)
{
    int tes = sum[rt].add;
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    sum[rt].add = tes;
}
void pushd(int rt)
{
    if (sum[rt].add != -1)
    {
        sum[rt<<1] = sum[rt].add;
        sum[rt<<1|1] = sum[rt].add;
        sum[rt<<1].add = sum[rt].add;
        sum[rt<<1|1].add = sum[rt].add;
        sum[rt].add = -1;
    }
}
void build(int l,int r,int rt=1)
{
    sum[rt].add = -1;
    if (l == r)
    {
        sum[rt] = -1;
        return ;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushu(rt);
}
void update(int L,int R,int c,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        sum[rt] = c ;
        sum[rt].add = c;
        return ;
    }
    pushd(rt );
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, lson);
    if (m < R) update(L, R, c, rson);
    pushu(rt);
}
node query(int L,int R,int l,int r,int rt=1)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    pushd(rt);
    node ret;
    int m = (l + r) >> 1;
    ret.num = 0;
    if (L <= m) ret =ret + query(L, R, lson);
    if (m < R) ret = ret + query(L, R, rson);
    return ret;
}

void init()
{
    memset(pre, -1, sizeof(pre));
    ecnt=0;
}
void edg(int u,int v)
{
    e[ecnt].v=v;
    e[ecnt].next=pre[u];
    pre[u]=ecnt++;
}
void dfs(int u)
{
    sz[u]=1;
    son[u]=0;
    for(int i=pre[u]; ~i; i=e[i].next)
    {
        int v=e[i].v;
        if(fa[u]!=v)
        {
            fa[v]=u;
            dep[v]=dep[u]+1;
            dfs(v);
            sz[u]+=sz[v];
            if(sz[v]>sz[son[u]])son[u]=v;
        }
    }
}
void butree(int u,int tp)
{
    top[u]=tp,w[u]=++nnum;
    if(son[u])butree(son[u],tp);
    for(int i=pre[u]; ~i; i=e[i].next)
        if(e[i].v!=fa[u]&&e[i].v!=son[u])
            butree(e[i].v,e[i].v);
}
void modify(int u,int v,int c)
{
    int f1=top[u],f2=top[v];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
            swap(f1,f2),swap(u,v);
        update(w[f1],w[u],c,1,nnum);
        u=fa[f1];
        f1=top[u];
    }
    if(u==v)return;
    if(dep[u]>dep[v])swap(u,v);
    update(w[son[u]],w[v],c,1,nnum);
}

node fd(int u,int v)
{
    int f1=top[u],f2=top[v];
    node l, r;
    l.num = r.num = 0;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
            swap(f1,f2),swap(u,v),swap(l,r);
        r =query(w[f1],w[u],1,nnum) + r;
        u=fa[f1];
        f1=top[u];
    }
    if(u==v)
    {
        swap(l.l,l.r);
        return l+r;
    }
    if(dep[u]>dep[v])swap(u,v),swap(l,r);
    l = query(w[son[u]],w[v],1,nnum)+l;
    swap(l.l,l.r);
    return l+r;
}

int main()
{
    int n,m;
    char s[20];
    int l,r,q;
    while(~scanf("%d%d",&n,&m))
    {
        int root=1;
        memset(sum,0,sizeof(sum));
        memset(sz,0,sizeof(sz));
        init();
        fa[1]=nnum=dep[1]=0;
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            edg(a[i],b[i]);
            edg(b[i],a[i]);
        }
        dfs(root);
        butree(root,root);
        build(1,nnum);
        for(int i=1; i<n; i++)
        {
            int u = a[i];
            int v = b[i];
            if (dep[u] > dep[v])
            {
                swap(u, v);
                swap(a[i], b[i]);
            }
            update(w[v],w[v],c[i],1,nnum);
        }
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d%d",&l,&r);
                printf("%d\n",fd(l,r).num);
            }
            else
            {
                scanf("%d%d%d",&l,&r,&q);
                modify(l,r,q);
            }
        }
    }
    return 0;
}
//1003	hannnnah_j’s Biological Test
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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL jc[1000010],ny[1000010];
LL C(LL n, LL m)
{
    return jc[n+m-1]*ny[n]%mod*ny[m-1]%mod;
}
int main(){
    LL n,m,k;
    int t;
    jc[0]=ny[0]=1;
    for(int i=1;i<=1000000;i++) jc[i]=jc[i-1]*i%mod;
    ny[1000000]=powmod(jc[1000000],mod-2);
    for(int i=999999;i>=1;i--) ny[i]=ny[i+1]*(i+1)%mod;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&n,&m,&k);
        if(m==1){
            printf("%d\n",n);
            continue;
        }
        if(n-m-m*k<0){
            puts("0");
            continue;
        }
        printf("%lld\n",(C(n-m-m*k,m+1)+C(n-m-m*k,m)*k)%mod);
    }
    return 0;
}
//1004	Mathematician QSC
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
//const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
LL MOD=0;
LL powmod(LL a,LL b,LL mod) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define Matr 5 //矩阵大小,注意能小就小   矩阵从1开始   所以Matr 要+1   最大可以100

struct mat//矩阵结构体，a表示内容，size大小 矩阵从1开始   但size不用加一
{
    LL a[Matr][Matr];
    mat()//构造函数
    {
        memset(a,0,sizeof(a));
    }
};
int Size=0;
mat multi(mat m1,mat m2)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    for(int i=1; i<=Size; i++)
        for(int j=1; j<=Size; j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(int k=1; k<=Size; k++)
                    ans.a[i][k]=(ans.a[i][k]+m1.a[i][j]*m2.a[j][k])%MOD; //i行k列第j项
    return ans;
}

mat quickmulti(mat m,LL n)//二分快速幂
{
    mat ans=mat();
    int i;
    for(i=1; i<=Size; i++)ans.a[i][i]=1;
    while(n)
    {
        if(n&1LL)ans=multi(m,ans);//奇乘偶子乘 挺好记的.
        m=multi(m,m);
        n>>=1;
    }
    return ans;
}

void print(mat m)//输出矩阵信息，debug用
{
    int i,j;
    printf("%d\n",Size);
    for(i=1; i<=Size; i++)
    {
        for(j=1; j<=Size; j++)
            printf("%d ",m.a[i][j]);
        printf("\n");
    }
}
LL eular(LL n)
{
    LL ans = n;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ans -= ans/i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1)ans -= ans/n;

    return ans;
}
LL g[]={0,1,5,30,174,1015,5915,34476,200940,1171165,6826049,39785130,231884730};
int main()
{
    int t;
    LL n,y,x,s;
    Size=4;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&y,&x,&s);
        LL phi=eular(s+1);
        if(n*y<=12){
            if(g[n*y]<phi){
                printf("%lld\n",powmod(x,g[n*y],s+1));
                continue;
            }
        }
        MOD=phi;
        mat gz=mat(),chu=mat();
        chu.a[1][1]=5;chu.a[2][1]=4;chu.a[3][1]=1;chu.a[4][1]=0;
        gz.a[1][1]=1,gz.a[1][2]=5,gz.a[1][3]=5,gz.a[1][4]=-1;
        gz.a[2][1]=0,gz.a[2][2]=5,gz.a[2][3]=5,gz.a[2][4]=-1;
        gz.a[3][1]=0,gz.a[3][2]=1,gz.a[3][3]=0,gz.a[3][4]=0;
        gz.a[4][1]=0,gz.a[4][2]=0,gz.a[4][3]=1,gz.a[4][4]=0;
        chu=multi(quickmulti(gz,n*y-2),chu);
        printf("%lld\n",powmod(x,chu.a[1][1]+phi,s+1));
    }
    return 0;
}
//1009	QSC and Master
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#include<bits/stdc++.h>
#define ll long long
ll aaaa[5005],jiazhi[5005];
ll DP[5050],zsum[5050];
int DP1[1000][1000];
void kuohaopipei(int n)
{
    memset(DP1,0,sizeof(DP1));
    for(int i=1; i<=n; i++)
        DP1[i][i]=1;
    for(int len=1; len<n; len++)
    {
        for(int i=1; i+len<=n; i++)
        {
            int j=i+len;
            DP1[i][j]=10000;
            if(__gcd(aaaa[i],aaaa[j])>1)
                DP1[i][j]=min(DP1[i][j],DP1[i+1][j-1]);
            for(int k=i; k<j; k++)
            {
                DP1[i][j] = min(DP1[i][j],DP1[i][k]+DP1[k+1][j]);
            }
        }
    }
}
void solve(int n)
{
    for(int i=2; i<=n; i++)
    {
        DP[i]=DP[i-1];
        for(int k=1; k<=i/2; k++)
        {
            int l=i-2*k+1;
            int r=i;
            if(DP1[l][r]==0)
            {
                DP[i]=max(DP[i],DP[i-2*k]+zsum[i]-zsum[i-2*k]);
            }
        }
    }
    printf("%lld\n",DP[n]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(DP,0,sizeof(DP));
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%lld",&aaaa[i]);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld",&jiazhi[i]);
            zsum[i]=zsum[i-1]+jiazhi[i];
        }
        kuohaopipei(n);
        solve(n);
    }
    return 0;
}
//1010	Count primes
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
const int MAXN=1000010;
#define MAX 1000010
#define sb(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define cb(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define isprime(x) (( (x) && ((x)&1) && (!cb(ar, (x)))) || ((x) == 2))

LL dp[91][50010];
unsigned int ar[(10000010 >> 6) + 5] = {0};
int len = 0, pri[666666], cnt[1000010];

void solve()
{
    sb(ar, 0), sb(ar, 1);
    for (int i = 3; (i * i) < MAXN; i++, i++)
    {
        if (!cb(ar, i))
        {
            int k = i << 1;
            for (int j = (i * i); j < MAXN; j += k)
            {
                sb(ar, j);
            }
        }
    }
    for (int i = 1; i < MAXN; i++)
    {
        cnt[i] = cnt[i - 1];
        if (isprime(i)) pri[len++] = i, cnt[i]++;
    }
}

void init()
{
    solve();
    for (int n = 0; n < 90; n++)
    {
        for (int m = 0; m < 50010; m++)
        {
            if (!n) dp[n][m] = m;
            else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / pri[n - 1]];
        }
    }
}

LL TT(LL m, int n)
{
    if (n == 0) return m;
    if (pri[n - 1] >= m) return 1;
    if (m < 50010  && n < 90) return dp[n][m];
    return TT(m, n - 1) - TT(m / pri[n - 1], n - 1);
}

LL Lehmer(LL m)
{
    if (m < MAX)
        return cnt[m];
    LL w, res = 0;
    int i, a, s, c, x, y;
    s = sqrt(0.9 + m), y = c = cbrt(0.9 + m);
    a = cnt[y], res = TT(m, a) + a - 1;
    for (i = a; pri[i] <= s; i++) res = res - Lehmer(m / pri[i]) + Lehmer(pri[i]) - 1;
    return res;
}


int main()
{
    init();
    LL n, res;
    while(~scanf("%lld",&n))
    {
        printf("%lld\n",Lehmer(n));
    }
    return 0;
}
