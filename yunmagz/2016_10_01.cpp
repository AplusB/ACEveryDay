//Codeforces Round #374 (Div. 2)
//A - One-dimensional Japanese Crossword
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
VI ans;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    s.pb('W');
    int f=0,cnt=0;
    for(int i=0;i<=n;i++){
        if(s[i]=='B') cnt++;
        else {
            if(cnt)
            {
                ans.pb(cnt);
                cnt=0;
            }
        }
    }
    cout<<SZ(ans)<<endl;
    for(auto i:ans) cout<<i<<" ";
    return 0;
}
//B - Passwords
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
string ss;
int a[110];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ss;
        a[i]=SZ(ss);
    }
    cin>>ss;
    int l=SZ(ss);
    sort(a,a+n);
    int ans=1,res=0;
    for(int i=0;i<n;i++){
        if(a[i]<l) ans++;
        if(a[i]<=l) res++;
    }
    cout<<ans+(ans-1)/k*5<<" "<<res+(res-1)/k*5<<endl;
    return 0;
}
//C - Journey
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
vector<PII>g[5010];
int dp[5001][5001],pre[5001][5001];
bool vis[5001][5001];
int n,m,u,v,T,t;
queue<PII>q;
void bfs(){
    vis[1][1]=1;
    dp[1][1]=0;
    q.push({1,1});
    while(!q.empty()){
        PII aa=q.front();
        int x=aa.fi,y=aa.se;
        q.pop();
        vis[x][y]=0;
        int l=SZ(g[x]);
        for(int i=0;i<l;i++){
            int xx=g[x][i].fi;
            int co=g[x][i].se;
            if(dp[x][y]+co>T) continue;
            if(dp[xx][y+1]>dp[x][y]+co){
                dp[xx][y+1]=dp[x][y]+co;
                pre[xx][y+1]=x;
                if(vis[xx][y+1]) continue;
                vis[xx][y+1]=1;
                q.push({xx,y+1});
            }
        }
    }
}
VI ans;
int main()
{
    cin>>n>>m>>T;
    memset(dp,inf,sizeof dp);
    for(int i=0;i<m;i++){
        cin>>u>>v>>t;
        g[u].pb(mp(v,t));
    }
    bfs();
    int j=0;
    for(int i=n;i>=1;i--){
        if(dp[n][i]<=T){
            j=i;
            break;
        }
    }
    ans.pb(n);
    while(pre[n][j]){
        ans.pb(pre[n][j]);
        n=pre[n][j];
        j--;
    }
    int res=SZ(ans);
    cout<<res<<endl;
    for(int i=res-1;i>=0;i--) cout<<ans[i]<<" ";
    return 0;
}


//AtCoder Grand Contest 005
//A - STring
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
 
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<SZ(s)-1;){
        if(s[i]=='S'&&s[i+1]=='T'){
            s.erase(i,2);
            if(i) i--;
        }
        else i++;
    }
    cout<<SZ(s)<<endl;
    return 0;
}
//B - Minimum Sum
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
 
int n,top;
int a[200005],s[200005],ans1[200005],ans2[200005];
int main()
{
    int n;
    cin>>n;
    LL ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i;i--)
	{
		while(top&&a[s[top]]>a[i])top--;
		ans1[i]=s[top]?s[top]:n+1;
		s[++top]=i;
	}
    reverse(a+1,a+n+1);
    top=0;
    for(int i=n;i;i--)
	{
		while(top&&a[s[top]]>a[i])top--;
		ans2[i]=s[top]?n-s[top]+1:0;
		s[++top]=i;
	}
    for(int i=1;i<=n;i++){
        ans+=1LL*(ans1[i]-i)*(i-ans2[n-i+1])*a[n-i+1];
//        cout<<ans1[i]<<" "<<ans2[n-i+1]<<endl;
//    cout<<ans<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
