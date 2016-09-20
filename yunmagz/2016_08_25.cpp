//AIM Tech Round 3 (Div. 2)
//A - Juicer
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
    int n,b,d,a;
    cin>>n>>b>>d;
    int sum=0,ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        if(a>b) continue;
        sum+=a;
        if(sum>d){
            ans++;
            sum=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
//B - Checkpoints
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
int x[100010];
int main()
{
    int n,b,d;
    LL a;
    cin>>n>>a;
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==2){
        cout<<min(abs(x[0]-a),abs(x[1]-a))<<endl;
        return 0;
    }
    x[n]=a;
    n++;
    sort(x,x+n);
    if(x[0]==a){
        cout<<x[n-2]-a<<endl;
        return 0;
    }
    if(x[n-1]==a){
        cout<<a-x[1]<<endl;
        return 0;
    }
    cout<<min(min(abs(a-x[1]),abs(a-x[n-1]))+abs(x[n-1]-x[1]),min(abs(a-x[n-2]),abs(a-x[0]))+abs(x[n-2]-x[0]));
    return 0;
}
//C - Letters Cyclic Shift
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
int x[100010];
int main()
{
    string s,ss;
    cin>>s;
    ss=s;
    int n=SZ(s);
    int f=0;
    if(n==1&&s[0]=='a'){
        puts("z");
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]!='a') f=1;
        if(f){
            if(s[i]=='a') break;
            s[i]--;
        }
    }
    if(ss==s) s[n-1]='z';
    cout<<s<<endl;
    return 0;
}
