//CODE FESTIVAL 2016 qual B
//A - Signboard
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
string s;
string ss="CODEFESTIVAL2016";
int main() {
	int n;
	cin>>s;
	int ans=0;
	for(int i=0;i<16;i++){
        if(s[i]!=ss[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
//B - Qualification simulator
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
string s;
string ss="CODEFESTIVAL2016";
int main() {
	int n,a,b;
	cin>>n>>a>>b;
	cin>>s;
	int l=SZ(s);
	int ca=0,cb=0;
	for(int i=0;i<l;i++){
        if(s[i]=='c') puts("No");
        else if(s[i]=='a'){
            if(ca+cb<a+b){
                puts("Yes");
                ca++;
            }
            else puts("No");
        }
        else{
            if(cb<b&&ca+cb<a+b){
                puts("Yes");
                cb++;
            }
            else puts("No");
        }
	}
	return 0;
}
//C - Gr-idian MST
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
struct node{
    int v,p;
}a[200010];
bool cmp(node a,node b){
    return a.v<b.v;
}
int main() {
    int w,h;
    cin>>w>>h;
    int mnp=999999,mnq=999999;
    for(int i=0;i<w;i++){
        cin>>a[i].v;
        a[i].p=0;
    }
    for(int i=w;i<h+w;i++){
        cin>>a[i].v;
        a[i].p=1;
    }
    LL ans=0;
    sort(a,a+w+h,cmp);
    int cw=0,ch=0;
    for(int i=0;i<h+w;i++){
        if(a[i].p){
            ans+=(LL)a[i].v*(w+1-ch);
            cw++;
        }
        else {
            ans+=(LL)a[i].v*(h+1-cw);
            ch++;
        }
    }
    cout<<ans<<endl;
	return 0;
}
//D - Greedy customers
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
const int mod=1e9+7;
const double eps=1e-8;
const LL inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
 
int main(){
    int n,a;
    cin>>n;
    LL ans = 0;
    int mx=1;
    for(int i = 1; i <= n; i++)
    {
        cin>>a;
        int m= a/mx;
        if(a%mx==0)m--;
        if(a>=mx)
        {
            ans+=m;
            if(a==mx||i==1) mx++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
