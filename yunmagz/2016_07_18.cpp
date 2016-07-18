//Codeforces Round #362 (Div. 2)
//E - PLEASE
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
int main(){
    int n;
    LL a;
    cin>>n;
    LL q=(mod-1)/2,d=2;
    for(int i=0;i<n;i++){
        cin>>a;
        q=powmod(q,a);
        d=powmod(d,a);
    }
    d=d*powmod(2,mod-2)%mod;
    q=(q*2+1)%mod*powmod(3,mod-2)%mod;
    cout<<q*d%mod<<"/"<<d<<endl;
    return 0;
}
