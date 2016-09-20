//Educational Codeforces Round 16
//A - King Moves
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

int main()
{
    char n[5];
    int f1=0,f2=0;
    cin>>n;
    if(n[0]=='a'||n[0]=='h') f1=1;
    if(n[1]=='1'||n[1]=='8') f2=1;
    if(f1&&f2) puts("3");
    else if(f1||f2) puts("5");
    else puts("8");
    return 0;
}
//B - Optimal Point on a Line
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
int n,a[300010];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    cout<<a[(n+1)/2]<<endl;
    return 0;
}
//C - Magic Odd Square
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
int a[55][55];
void solve(int n)
{
    int x=0,y=n/2;
    for(int i=1;i<=n*n;i++)
    {
        a[x][y]=i;
        x=(x+n-1)%n;
        y=(y+1)%n;
        if(a[x][y])
        {
            x=(x+2)%n;
            y=(y+n-1)%n;
        }
    }
}
int main()
{
	int n;
	cin>>n;
	int cnt=1;
	solve(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            printf("%d%c",a[i][j],j==n-1?'\n':' ');
	return 0;
}
//E - Generate a String
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
LL dp[11234567];
int main()
{
	int n;
	LL x,y;
	cin>>n>>x>>y;
	memset(dp,-1,sizeof(dp));
	dp[0] = 0;
	for(int i = 0; i <= n; ++i)
	{
		if(i*2 <= n)
		{
			int tmp = i*2;

			while(dp[tmp] == -1 || dp[tmp] > dp[i]+y+x*(i*2-tmp))
			{
				dp[tmp] = dp[i]+y+x*(i*2-tmp);
				tmp--;
			}
		}
		else
		{
			if(dp[n] == -1) dp[n] = dp[i]+y+(i*2-n)*x;
			else dp[n] = min(dp[n],dp[i]+y+(i*2-n)*x);
		}
		if(i+1 <= n)
		{
			if(dp[i+1] == -1) dp[i+1] = dp[i]+x;
			else dp[i+1] = min(dp[i+1],dp[i]+x);
		}
	}
	cout<<dp[n]<<endl;

	return 0;
}
