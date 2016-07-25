//Codeforces Round #364 (Div. 2)
//A - Cards
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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}\
int a[110],v[110];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n/2;
    for(int i=0;i<n;i++){
        if(!v[i]){
            v[i]=1;
            for(int j=0;j<n;j++){
                if(!v[j]&&a[i]+a[j]==sum){
                    v[j]=1;
                    cout<<i+1<<" "<<j+1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
//B - Cells Not Under Attack
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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}\
int X[100010],Y[100010];
int main()
{
    LL n,m,x,y,xx=0,yy=0;
    cin>>n>>m;
    LL sum=1LL*n*n;
    for(int i=0;i<m;i++){
        scanf("%I64d%I64d",&x,&y);
        if(!X[x]){
            X[x]=1;
            xx++;
            sum-=n-yy;
        }
        if(!Y[y]){
            Y[y]=1;
            yy++;
            sum-=n-xx;
        }
        printf("%I64d ",sum);
    }
    return 0;
}
//C - They Are Everywhere
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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}\
string s;
set<int>v;
int vv[1111];
int a[1111];
int main()
{
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++)
        a[s[i]]++;
    int cnt=0;
    for(int i='a';i<='z';i++)
        if(a[i]) cnt++;
    for(int i='A';i<='Z';i++)
        if(a[i]) cnt++;
    int i=0,j=0,ans=n;
    while(i<n&&j<n){
        int m=v.size();
        if(m==cnt){
            ans=min(ans,j-i);
            vv[s[i]]--;
            if(!vv[s[i]]) v.erase(s[i]);
            i++;
        }
        else if(m<cnt){
            v.insert(s[j]);
            vv[s[j]]++;
            j++;
        }
    }
    while(v.size()==cnt){
        ans=min(ans,j-i);
        vv[s[i]]--;
        if(!vv[s[i]]) v.erase(s[i]);
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
//D - As Fast As Possible
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
LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}\
string s;
set<int>v;
int vv[1111];
int a[1111];
int main()
{
    int n,k;
    double l,v1,v2;
    cin>>n>>l>>v1>>v2>>k;
    int m=n/k;
    if(n%k) m++;
    m--;
    double x=l/(((m+1)/(v2-v1)+m/(v1+v2))*v1+1);
    double ans=x/(v2-v1)*(m+1)+x/(v1+v2)*m;
    printf("%.12lf\n",ans);
    return 0;
}
