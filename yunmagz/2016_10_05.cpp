//AtCoder Grand Contest 005
//C - Tree Restoring
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int v[110];
int main()
{
    int n,a;
    cin>>n;
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a;
        v[a]++;
        mx=max(mx,a);
    }
    int mn=(mx+1)/2;
    for(int i=1;i<mn;i++)
        if(v[i]) return 0*puts("Impossible");
    for(int i=mn+1;i<=mx;i++)
        if(v[i]<2) return 0*puts("Impossible");
    if(v[mn]!=(mx&1)+1) return 0*puts("Impossible");
    puts("Possible");
    return 0;
}
