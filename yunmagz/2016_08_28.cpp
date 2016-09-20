//AtCoder Regular Contest 060
//C - 高橋君とカード / Tak and Cards
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
LL dp[55][55][2600];
int x[55];
int main()
{
    int n,a;
    cin>>n>>a;
    for(int i=1;i<=n;i++) cin>>x[i];
    dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            for(int k=0;k<=2500;k++){
                if(dp[i-1][j][k]){
                    dp[i][j+1][k+x[i]]+=dp[i-1][j][k];
                    dp[i][j][k]+=dp[i-1][j][k];
                }
            }
        }
    }
    LL ans=0;
    for(int i=1;i<=n;i++) ans+=dp[n][i][i*a];
    cout<<ans<<endl;
	return 0;
}
