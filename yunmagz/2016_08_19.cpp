//CF13A - Numbers
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
    int n;
    cin>>n;
    int ans=0;
    for(int i=2;i<n;i++){
        int m=n;
        while(m){
            ans+=m%i;
            m/=i;
        }
    }
    int g=__gcd(ans,n-2);
    printf("%d/%d",ans/g,(n-2)/g);
    return 0;
}
