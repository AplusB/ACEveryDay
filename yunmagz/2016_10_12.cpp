//AtCoder Regular Contest 060
//E - 高橋君とホテル / Tak and Hotels
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e4+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[100010];
int dp[100010][20];
int main() {
    int n,L,q;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d%d",&L,&q);
    for(int i=0;i<n;i++) dp[i][0]=upper_bound(a+i,a+n,a[i]+L)-a-1;;
    for(int i=0;i<18;i++)
        for(int j=0;j<n;j++)
            dp[j][i+1]=dp[dp[j][i]][i];
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r) swap(l,r);
        l--;
        r--;
        int ans=0;
        for(int i=17;i>=0;i--){
            if(dp[l][i]<r){
                ans+=1<<i;
                l=dp[l][i];
            }
        }
        printf("%d\n",ans+1);
    }
	return 0;
}
