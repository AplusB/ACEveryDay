//Codeforces Round #371 (Div. 2)
//E - Sonya and Problem Wihtout a Legend
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
LL dp[2][3010];
LL a[3010],b[3010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]-=i;
        b[i]=a[i];
    }
    sort(b,b+n);
    int now=0;
    for(int i=0;i<n;i++){
        now^=1;
        dp[now][0]=dp[now^1][0]+abs(a[i]-b[0]);
        for(int j=1;j<n;j++)
            dp[now][j]=min(dp[now][j-1],dp[now^1][j]+abs(a[i]-b[j]));
    }
    cout<<dp[now][n-1]<<endl;
    return 0;
}
