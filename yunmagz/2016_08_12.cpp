//Codeforces Round #367 (Div. 2)
//A - Beru-taxi
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
double d(double x,double y,double xx,double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int main()
{
    int n;
    double a,b,x,y,v;
    double ans=999999999.0;
    cin>>a>>b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y>>v;
        ans=min(ans,d(a,b,x,y)/v);
    }
    printf("%.12lf\n",ans);
    return 0;
}
//B - Interesting drink
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int x[100010],pre[100010];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&x[i]);
    sort(x,x+n);
    x[n]=-1;
    for(int i=1,j=0;i<=100000;i++){
        pre[i]=pre[i-1];
        if(i==x[j]){
            while(i==x[j]){
                pre[i]++;
                j++;
            }
        }
    }
    int q,a;
    cin>>q;
    while(q--){
        scanf("%d",&a);
        if(a>100000) printf("%d\n",n);
        else printf("%d\n",pre[a]);
    }
    return 0;
}
//C - Hard problem
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[100010];
string s[2][100010];
LL dp[2][100010];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[0][i]=1LL<<62;
        dp[1][i]=1LL<<62;
    }
    for(int i=1;i<=n;i++){
        cin>>s[0][i];
        s[1][i]=s[0][i];
        reverse(all(s[1][i]));
        if(i==1){
            dp[0][i]=0;
            dp[1][i]=a[i];
        }
        else {
            if(s[0][i]>=s[0][i-1])dp[0][i]=min(dp[0][i-1],dp[0][i]);
            if(s[0][i]>=s[1][i-1])dp[0][i]=min(dp[1][i-1],dp[0][i]);
            if(s[1][i]>=s[0][i-1])dp[1][i]=min(dp[0][i-1]+a[i],dp[1][i]);
            if(s[1][i]>=s[1][i-1])dp[1][i]=min(dp[1][i-1]+a[i],dp[1][i]);
        }
    }
    LL ans=min(dp[0][n],dp[1][n]);
    if(ans==(1LL<<62)) puts("-1");
    else cout<<ans<<endl;
    return 0;
}
