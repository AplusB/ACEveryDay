//Codeforces Round #369 (Div. 2)
//B - Chris and Magic Square
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
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[550][550];
set<LL>s;
int main()
{
    int n;
    cin>>n;
    int x,y,f=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                x=i;
                y=j;
            }
        }
    }
    if(n==1) return 0*puts("1");
    LL sum=0;
    for(int i=0;i<n;i++){
        if(i==x) continue;
        sum=0;
        for(int j=0;j<n;j++) sum+=a[i][j];
        s.insert(sum);
    }
    for(int i=0;i<n;i++){
        if(i==y) continue;
        sum=0;
        for(int j=0;j<n;j++) sum+=a[j][i];
        s.insert(sum);
    }
    if(x!=y){
        sum=0;
        for(int i=0;i<n;i++) sum+=a[i][i];
        s.insert(sum);
    }
    if(x!=n-y-1){
        sum=0;
        for(int i=0;i<n;i++) sum+=a[i][n-i-1];
        s.insert(sum);
    }
    int m=SZ(s);
    LL ans=0;
    if(m!=1) return 0*puts("-1");
    else {
        set<LL>::iterator it=s.begin();
        ans=*it;
        s.clear();
        sum=0;
        for(int j=0;j<n;j++) sum+=a[x][j];
        s.insert(sum);
        sum=0;
        for(int j=0;j<n;j++) sum+=a[j][y];
        s.insert(sum);
        if(x==y){
            sum=0;
            for(int i=0;i<n;i++) sum+=a[i][i];
            s.insert(sum);
        }
        if(x==n-y-1){
            sum=0;
            for(int i=0;i<n;i++) sum+=a[i][n-i-1];
            s.insert(sum);
        }
        if(SZ(s)!=1) return 0*puts("-1");
        else {
            it=s.begin();
            ans-=(*it);
            if(ans<=0) ans=-1;
            cout<<ans<<endl;
        }
    }
	return 0;
}
//C - Coloring Trees
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
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL p[105][105],a[105];
LL dp[105][105][105];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>p[i][j];
    int now=0;
    memset(dp[0],0x3f,sizeof dp[0]);
    dp[0][0][0]=0;
    for(int i=1;i<=n;i++){
        now^=1;
        memset(dp[now],0x3f,sizeof dp[now]);
        for(int j=0;j<=n;j++){
            for(int h=0;h<=m;h++){
                if(a[i]){
                    if(a[i]==h) dp[now][j][a[i]]=min(dp[now][j][a[i]],dp[now^1][j][h]);
                    else dp[now][j+1][a[i]]=min(dp[now][j+1][a[i]],dp[now^1][j][h]);
                }
                else {
                    for(int g=1;g<=m;g++){
                        if(g==h) dp[now][j][g]=min(dp[now][j][g],dp[now^1][j][h]+p[i][g]);
                        else dp[now][j+1][g]=min(dp[now][j+1][g],dp[now^1][j][h]+p[i][g]);
                    }
                }
            }
        }
    }
    LL ans=(1LL<<61);
    for(int i=0;i<=m;i++) ans=min(ans,dp[now][k][i]);
    if(ans==(1LL<<61)) ans=-1;
    cout<<ans<<endl;
	return 0;
}
