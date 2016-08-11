//2016 Multi-University Training Contest 6
//1001 A Boring Question
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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    int t;
    LL n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&m);
        printf("%lld\n",((powmod(m,n+1)-1)%mod+mod)%mod*powmod(m-1,mod-2)%mod);
    }
    return 0;
}
//1003 A Simple Nim
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
//LL powmod(LL a,LL b) {LL re=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int main()
{
    int t,n,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a);
            if(a%8==0) ans^=a-1;
            else if(a%8==7) ans^=a+1;
            else ans^=a;
        }
        if(ans) puts("First player wins.");
        else puts("Second player wins.");
    }
    return 0;
}
