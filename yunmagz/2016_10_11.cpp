//2017微软秋季校园招聘在线编程笔试
//A	Shortening Sequence
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
const LL inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main(){
    int n,a;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        if(a&1) ans++;
        else ans--;
    }
    cout<<abs(ans)<<endl;
    return 0;
}
//B	Composition
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
const LL inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
string s,ss;
int a[30][30];
int dp[30];
int main(){
    int n,m;
    cin>>n>>s;
    cin>>m;
    while(m--){
        cin>>ss;
        a[ss[0]-'a'][ss[1]-'a']=1;
        a[ss[1]-'a'][ss[0]-'a']=1;
    }
    int mx=0;
    for(int i=0;i<n;i++){
        int x=s[i]-'a';
        int tmp=1;
        for(int j=0;j<26;j++){
            if(a[x][j]) continue;
            tmp=max(tmp,dp[j]+1);
        }
        dp[x]=tmp;
        mx=max(mx,dp[x]);
    }
    cout<<n-mx<<endl;
    return 0;
}
