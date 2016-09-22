//Codeforces Round #371 (Div. 2)
//A - Meeting of Old Friends
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
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
LL l1,l2,r1,r2,k;
int main(){
    cin>>l1>>r1>>l2>>r2>>k;
    if(l1>r2||r1<l2) return 0*puts("0");
    LL l=max(l1,l2),r=min(r1,r2);
    if(k>=l&&k<=r) cout<<r-l<<endl;
    else cout<<r-l+1<<endl;
    return 0;
}
//B - Filya and Homework
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
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
set<int>s;
int a[5];
int main(){
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    if(SZ(s)<3) return 0*puts("YES");
    if(SZ(s)!=3) return 0*puts("NO");
    int j=0;
    for(auto i:s)
        a[j++]=i;
    if(a[2]-a[1]==a[1]-a[0]) puts("YES");
    else puts("NO");
    return 0;
}
//C - Sonya and Queries
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
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
map<string,int>m;
string s;
int main(){
    int n,l;
    LL x;
    cin>>n;
    while(n--){
        cin>>s>>x;
        if(s[0]=='+'){
            s="";
            while(x){
                s+=((x%10)&1)?"1":"0";
                x/=10;
            }
            while(SZ(s)<18){
                s+="0";
            }
            m[s]++;
        }
        else if(s[0]=='-'){
            s="";
            while(x){
                s+=((x%10)&1)?"1":"0";
                x/=10;
            }
            while(SZ(s)<18){
                s+="0";
            }
            m[s]--;
        }
        else {
            s="";
            while(x){
                s+=((x%10)&1)?"1":"0";
                x/=10;
            }
            while(SZ(s)<18){
                s+="0";
            }
            cout<<m[s]<<endl;
        }
    }
    return 0;
}
