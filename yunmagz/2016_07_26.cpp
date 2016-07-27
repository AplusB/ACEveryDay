//Codeforces 588A
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
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main(){
    int n,a,p;
    cin>>n;
    int mn=110,ans=0;
    for(int i=0;i<n;i++){
        cin>>a>>p;
        mn=min(p,mn);
        ans+=a*mn;
    }
    cout<<ans<<endl;
    return 0;
}
//Codeforces 588B
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
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main(){
    LL n;
    cin>>n;
    LL ans=1;
    for(LL i=2;i*i<=n;i++){
        if(n%i==0){
            ans*=i;
        }
        while(n%i==0){
            n/=i;
        }
    }
    cout<<n*ans<<endl;
    return 0;
}
