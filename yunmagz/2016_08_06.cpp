//hdu5399 Too Simple
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
const LL mod=1e9+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL jc[123];
int v[123][123];
int main()
{
    jc[1]=1;
    for(int i=2; i<=100; i++)
    {
        jc[i]=jc[i-1]*i;
        jc[i]%=mod;
    }
    int n,m;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        LL ans=1;
        int cnt=0,ff=0,haha=0;
        for(int i=1; i<=m; i++)
        {
            int x;
            scanf("%d",&x);
            if(x==-1)
            {
                haha=1;
                cnt++;
            }
            else
            {
                int used[123];
                memset(used,0,sizeof(used));
                int kx=0;
                if(used[x]==0)
                {
                    used[x]=1;
                    kx++;
                }
                v[i][1]=x;
                for(int j=2; j<=n; j++)
                {
                    scanf("%d",&x);
                    v[i][j]=x;
                    if(used[x]==0)
                    {
                        used[x]=1;
                        kx++;
                    }
                }
                if(kx!=n) ff=1;
            }
        }
        for(int j=1; j<cnt; j++)
        {
            ans*=jc[n];
            ans%=mod;
        }
        if(ff==1) puts("0");
        else if(haha==0)
        {
            int f=0;
            for(int i=1; i<=n; i++)
            {
                int cur=v[m][i];
                for(int j=m-1; j>=1; j--)
                {
                    cur=v[j][cur];
                }
                if(cur!=i)
                {
                    f=1;
                    break;
                }
            }
            if(f==1) puts("0");
            else puts("1");
        }
        else printf("%I64d\n",ans);
    }
    return 0;
}
//hdu5400 Arithmetic Sequence
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
const LL mod=1e9+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL a[100010];
LL cal(LL x) {return x*(x+1)/2;}
int main()
{
    int n,d1,d2;
    while(cin>>n>>d1>>d2){
        for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
        LL pre=0,lst=0,ans=n;
        a[n]=-inf;
        for(int i=1;i<=n;i++){
            if(a[i]-a[i-1]==d1){
                if(lst){
                    ans+=cal(pre+lst);
                    pre=0;
                }
                pre++;
                lst=0;
            }
            else if(a[i]-a[i-1]==d2) lst++;
            else {
                ans+=cal(pre+lst);
                pre=lst=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//hdu5402 Travelling Salesman Problem
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
const LL mod=1e9+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int maxn = 105;
LL T, n, m, a[maxn][maxn], sum, x, y;

inline void read(int &x)
{
    char ch;
    while ((ch = getchar())<'0' || ch>'9');
    x = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - '0';
}

void get()
{
    x = 1;    y = 2;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m; j++)
            if (((i + j) & 1) && a[x][y] > a[i][j]) x = i, y = j;
}

int main()
{
    while (scanf("%lld%lld", &n, &m) !=EOF)
    {
        sum = 0;
        for (int i = 1; i <= n;i++)
            for (int j = 1; j <= m; j++)
            {
                scanf("%lld", &a[i][j]);
                sum += a[i][j];
            }
        if (n & 1 || m & 1)
        {
            printf("%lld\n", sum);
            if (n & 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j < m; j++)
                        if (i & 1) printf("R"); else printf("L");
                    if (i < n) printf("D"); else printf("\n");
                }
            }
            else
            {
                for (int i = 1; i <= m; i++)
                {
                    for (int j = 1; j < n; j++)
                        if (i & 1) printf("D"); else printf("U");
                    if (i < m) printf("R"); else printf("\n");
                }
            }
        }
        else
        {
            get();
            printf("%lld\n", sum - a[x][y]);
            for (int i = 1; i <= n; i += 2)
            {
                if (x == i || x == i + 1)
                {
                    for (int j = 1; j < y; j++)
                    {
                        if (j & 1) printf("D"); else printf("U");
                        printf("R");
                    }
                    if (y < m) printf("R");
                    for (int j = y + 1; j <= m; j++)
                    {
                        if (j & 1) printf("U"); else printf("D");
                        if (j < m) printf("R");
                    }
                    if (i < n - 1) printf("D");
                }
                else if (i < x)
                {
                    for (int j = 1; j < m; j++) printf("R");
                    printf("D");
                    for (int j = 1; j < m; j++) printf("L");
                    printf("D");
                }
                else
                {
                    for (int j = 1; j < m; j++) printf("L");
                    printf("D");
                    for (int j = 1; j < m; j++) printf("R");
                    if (i < n - 1) printf("D");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
