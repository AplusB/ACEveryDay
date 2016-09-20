//“玲珑杯”ACM比赛 Round #2
//F -- Bob and Alice are playing numbers
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const MAX = 2000100;
int n;
long long ans,ans1,ans2;
struct Trie
{
    int root, tot, next[MAX][2], en[MAX],sum[MAX];
    int Newnode()
    {
        memset(next[tot], -1, sizeof(next[tot]));
        en[tot] = 0;
        sum[tot]=0;
        return tot ++;
    }
    void Init()
    {
        tot = 0;
        root = Newnode();
    }
    void Insert(ll x)
    {
        int p = root;
        for(int i = 30; i >= 0; i--)
        {
            int idx = ((1 << i) & x) ? 1 : 0;
            if(next[p][idx] == -1)
                next[p][idx] = Newnode();
            sum[next[p][idx]]++;
            p = next[p][idx];
        }
      //  cout<<p<<" "<<x<<endl;
        en[p] = x;
    }
    void delt(ll x)
    {
        int p = root;
        for(int i = 30; i >= 0; i--)
        {
            int idx = ((1 << i) & x) ? 1 : 0;
            sum[next[p][idx]]--;
            p = next[p][idx];
        }
    }
    ll Search(ll x)
    {
        int p = root;
        for(int i = 30; i >= 0; i--)
        {
            int idx = ((1 << i) & x) ? 1 : 0;
            if(idx == 0)
            {
                p = (next[p][1] != -1&&sum[next[p][1]]>0)? next[p][1] : next[p][0];
            }
            else
            {
                p = (next[p][0] != -1&&sum[next[p][0]]>0)? next[p][0] : next[p][1];
            }
        }
        return x^en[p];
    }
    void Search1(ll x,int p,int i,long long res)
    {
        if(i==-1)
        {
            ans1=max(ans1,res);
            return;
        }
        if((res|((1<<(i+1))-1))<=ans1) return;
        int idx = ((1 << i) & x) ? 1 : 0;
        if(idx == 0)
        {
            if(next[p][1]!=-1&&sum[next[p][1]]>0) Search1(x,next[p][1],i-1,res);
            if(next[p][0]!=-1&&sum[next[p][0]]>0) Search1(x,next[p][0],i-1,res);
        }
        else
        {
            if(next[p][1] != -1&&sum[next[p][1]]>0) Search1(x,next[p][1],i-1,res|(1<<i));
            else Search1(x,next[p][0],i-1,res);
        }
    }
    void Search2(ll x,int p,int i,long long res)
    {
        if(i==-1)
        {
            ans2=max(ans2,res);
            return;
        }
        if((res|((1<<(i+1))-1))<=ans2) return;
        int idx = ((1 << i) & x) ? 1 : 0;
        if(idx == 1)
        {
            if(next[p][1]!=-1&&sum[next[p][1]]>0) Search2(x,next[p][1],i-1,res|(1<<i));
            if(next[p][0]!=-1&&sum[next[p][0]]>0) Search2(x,next[p][0],i-1,res|(1<<i));
        }
        else
        {
            if(next[p][1] != -1&&sum[next[p][1]]>0) Search2(x,next[p][1],i-1,res|(1<<i));
            else Search2(x,next[p][0],i-1,res);
        }
    }

}tr;
int a[110000];
int cal2()
{
    sort(a+1, a+n+1);
    int ans=a[n], maxn=0;
    for(int i=1; i<n; i++)
        maxn=max(maxn, a[i]|ans);
    return maxn;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int mark;
        long long ans=0;
        scanf("%d%d",&n,&mark);
        tr.Init();
        for(int i=0;i<n;i++) scanf("%d",&a[i]),tr.Insert(a[i]);
        ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            tr.delt(x);
            if(mark==2)  ans=max(ans,tr.Search(x));
            else if(mark==1) tr.Search1(x,tr.root,30,0),ans=max(ans,ans1);
            else tr.Search2(x,tr.root,30,0),ans=max(ans,ans2);
            tr.Insert(x);
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
//G -- Bob and Alice are playing factors
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

const int Times = 10;
const int N = 5500;

LL ct, cnt;
LL fac[N], num[N];

LL gcd(LL a, LL b)
{
    return b? gcd(b, a % b) : a;
}

LL multi(LL a, LL b, LL m)
{
    LL ans = 0;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = (ans + a) % m;
            b--;
        }
        b >>= 1;
        a = (a + a) % m;
    }
    return ans;
}

LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = multi(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi(a, a, m);
    }
    return ans;
}

bool Miller_Rabin(LL n)
{
    if(n == 2) return true;
    if(n < 2 || !(n & 1)) return false;
    LL m = n - 1;
    int k = 0;
    while((m & 1) == 0)
    {
        k++;
        m >>= 1;
    }
    for(int i=0; i<Times; i++)
    {
        LL a = rand() % (n - 1) + 1;
        LL x = quick_mod(a, m, n);
        LL y = 0;
        for(int j=0; j<k; j++)
        {
            y = multi(x, x, n);
            if(y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if(y != 1) return false;
    }
    return true;
}

LL pollard_rho(LL n, LL c)
{
    LL i = 1, k = 2;
    LL x = rand() % (n - 1) + 1;
    LL y = x;
    while(true)
    {
        i++;
        x = (multi(x, x, n) + c) % n;
        LL d = gcd((y - x + n) % n, n);
        if(1 < d && d < n) return d;
        if(y == x) return n;
        if(i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

void find(LL n, int c)
{
    if(n == 1) return;
    if(Miller_Rabin(n))
    {
        fac[ct++] = n;
        return ;
    }
    LL p = n;
    LL k = c;
    while(p >= n) p = pollard_rho(p, c--);
    find(p, k);
    find(n / p, k);
}
LL jc[110];
int main()
{
    jc[0]=1;
    for(int i=1;i<=100;i++)
        jc[i]=jc[i-1]*i%mod;
    LL n;
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ct = 0;
        find(n, 120);
        sort(fac, fac + ct);
        num[0] = 1;
        int k = 1;
        for(int i=1; i<ct; i++)
        {
            if(fac[i] == fac[i-1])
                ++num[k-1];
            else
            {
                num[k] = 1;
                fac[k++] = fac[i];
            }
        }
        cnt = k;
        LL ans=jc[ct];
        for(int i=0; i<cnt; i++){
            ans=(ans*powmod(jc[num[i]],mod-2))%mod;
        }
        printf("Case #%d: %d ",cas++,ct+1);
        cout<<ans<<endl;

    }
    return 0;
}
//I -- Bob and Alice are eating food
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define Matr 7 //矩阵大小,注意能小就小   矩阵从1开始   所以Matr 要+1   最大可以100
struct mat//矩阵结构体，a表示内容，size大小 矩阵从1开始   但size不用加一
{
    ll a[Matr][Matr];
    mat()//构造函数
    {
        memset(a,0,sizeof(a));
    }
};
int Size=0;

mat multi(mat m1,mat m2)//两个相等矩阵的乘法，对于稀疏矩阵，有0处不用运算的优化
{
    mat ans=mat();
    for(int i=1;i<=Size;i++)
        for(int j=1;j<=Size;j++)
            if(m1.a[i][j])//稀疏矩阵优化
                for(int k=1;k<=Size;k++)
                    ans.a[i][k]=(ans.a[i][k]+m1.a[i][j]*m2.a[j][k])%mod; //i行k列第j项
    return ans;
}

mat quickmulti(mat m,ll n)//二分快速幂
{
    mat ans=mat();
    int i;
    for(i=1;i<=Size;i++)ans.a[i][i]=1;
    while(n)
    {
        if(n&1)ans=multi(m,ans);//奇乘偶子乘 挺好记的.
        m=multi(m,m);
        n>>=1;
    }
    return ans;
}

void print(mat m)//输出矩阵信息，debug用
{
    int i,j;
    printf("%d\n",Size);
    for(i=1;i<=Size;i++)
    {
        for(j=1;j<=Size;j++)
			printf("%d ",m.a[i][j]);
        printf("\n");
    }
}

int main()
{
    int t,cas=1;
    ll n;
    scanf("%d", &t);
    while(t--){
        Size=4;
        scanf("%lld",&n);
        mat gz=mat(),chu=mat();
        chu.a[1][1]=1;
        gz.a[1][1]=gz.a[2][2]=gz.a[3][3]=gz.a[4][4]=4;
        gz.a[1][2]=gz.a[1][3]=gz.a[2][1]=gz.a[2][4]=gz.a[3][1]=gz.a[3][4]=gz.a[4][2]=gz.a[4][3]=1;
        chu=multi(chu,quickmulti(gz,n));
        printf("Case #%d: %lld\n",cas++,chu.a[1][1]);
    }
    return 0;
}
