//Codeforces Round #363 (Div. 2)
//A - Launch of Collider
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
const LL mod=1e9+7;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[200010];
int main()
{
	int n;
	string s;
	cin>>n;
	cin>>s;
	for(int i=0;i<n;i++) cin>>a[i];
	int ans=mod;
	for(int i=1;i<n;i++){
		if(s[i-1]=='R'&&s[i]=='L'){
			ans=min(ans,(a[i]-a[i-1])/2);
		}
	}
	if(ans==mod) ans=-1;
	cout<<ans<<endl;
    return 0;
}
//B - One Bomb
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
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
char s[1010][1010];
int c[1010],r[1010];
int main()
{
	int n,m;
	cin>>n>>m;
	int cnt=0;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='*'){
				cnt++;
				c[i]++;
				r[j]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(s[i][j]=='*'){
				if(c[i]+r[j]-1==cnt) return 0*printf("YES\n%d %d",i+1,j+1);
			}
			else if(c[i]+r[j]==cnt) return 0*printf("YES\n%d %d",i+1,j+1);
		}
	}
	puts("NO");
    return 0;
}
//C - Vacations
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
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[110],dp[110][4];//0 r   1 c   2 g
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(dp,inf,sizeof dp);
	dp[1][0]=1;
	if(a[1]==1){
		dp[1][1]=0;
	}
	else if(a[1]==2){
		dp[1][2]=0;
	}
	else if(a[1]==3){
		dp[1][1]=0;
		dp[1][2]=0;
	}
	for(int i=2;i<=n;i++){
		dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
		if(a[i]==1){
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
		}
		else if(a[i]==2){
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
		else if(a[i]==3){
			dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
			dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
		}
	}
	cout<<min(min(dp[n][0],dp[n][1]),dp[n][2])<<endl;
    return 0;
}
//D - Fix a Tree
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
const LL mod=1e9+7;
const int inf=0x3f3f3f3f;
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
VI g;
int v[200010],a[200010],bb[200010];
int main()
{
	int n;
	cin>>n;
	memset(v,-1,sizeof v);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) {
			g.pb(i);
			bb[i]=1;
		}
	}
	int f=SZ(g);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(v[i]==-1){
			cnt++;
			int x=i,pre=0;
			while(v[x]==-1){
				v[x]=cnt;
				pre=x;
				x=a[x];
			}
			if(v[x]==cnt){
				a[pre]=pre;
				//cout<<x<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i&& !bb[i]) g.pb(i);
	}
	for(int i=1;i<SZ(g);i++)
		a[g[i]]=g[0];
	if(f) cout<<SZ(g)-1<<endl;
	else cout<<SZ(g)<<endl;
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    return 0;
}
