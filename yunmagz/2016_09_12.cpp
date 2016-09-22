//Codeforces Round #370 (Div. 2)
//A - Memory and Crow
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
const LL INF=1e18;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL a[100010],b[100010];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1) cout<<a[i]+a[i-1]<<" ";
    }
    cout<<a[n];
    return 0;
}
//B - Memory and Trident
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
const LL INF=1e18;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int u,d,l,r;
int main(){
    string s;
    cin>>s;
    int n=SZ(s);
    if(n&1) return 0*puts("-1");
    for(int i=0;i<n;i++){
        if(s[i]=='U') u++;
        if(s[i]=='D') d++;
        if(s[i]=='L') l++;
        if(s[i]=='R') r++;
    }
    int mn=min(l,r)+min(u,d);
    cout<<n/2-mn<<endl;
    return 0;
}
//C - Memory and De-Evolution
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
const LL INF=1e18;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[5];
int main(){
    int n,m;
    cin>>n>>m;
    a[0]=a[1]=a[2]=m;
    int ans=0;
    while(1){
        if(a[0]==n&&a[1]==n&&a[2]==n) break;
        sort(a,a+3);
        a[0]=min(n,a[2]+a[1]-1);
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
