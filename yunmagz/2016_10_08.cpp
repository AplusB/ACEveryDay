//Intel Code Challenge Final Round (Div. 1 + Div. 2, Combined)
//A - Checking the Calendar
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
//typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e4+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
string s,ss;
string a[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};
int main(){
    int n,m;
    cin>>s>>ss;
    for(int i=0;i<7;i++)
        if(s==a[i]) n=i;
    for(int i=0;i<7;i++)
        if(ss==a[i]) m=i;
    int aa=(m+7-n)%7;
    if(aa==0||aa==2||aa==3) puts("YES");
    else puts("NO");
    return 0;
}
//B - Batch Sort
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
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[25][25];
VI aa[25],san;
int n,m;
bool ok(int x,int y){
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=m;j++){
            if(j==x){
                if(a[i][y]!=j) cnt++;
            }
            else if(j==y){
                if(a[i][x]!=j) cnt++;
            }
            else if(a[i][j]!=j) cnt++;
        }
        if(cnt!=0&&cnt!=2) return 0;
    }
    return 1;
}
int main(){
    cin>>n>>m;
    int f=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]!=j){
                aa[i].pb(j);
            }
        }
        if(SZ(aa[i])>4) return 0*puts("NO");
        if(SZ(aa[i])>=3){
            f=0;
            san.pb(i);
        }
    }
    if(f) return 0*puts("YES");
    for(int k=0;k<SZ(san);k++){
        int l=SZ(aa[san[k]]);
        for(int i=0;i<l;i++){
            for(int j=i+1;j<l;j++){
                if(ok(aa[san[k]][i],aa[san[k]][j])) return 0*puts("YES");
            }
        }
    }
    puts("NO");
    return 0;
}
//C - Ray Tracing
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
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
VI xl[2][200010];
LL ans[100010];
int x[100010],y[100010];
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        scanf("%d%d",&x[i],&y[i]);
        xl[0][x[i]+y[i]].pb(i);
        xl[1][y[i]-x[i]+100000].pb(i);
    }
    int xx,yy,f=1;//0 左上 1 右上 2 右下 3 左下
    int mn;
    int X=0,Y=0;
    LL cnt=0;
    while(1){
        if(f==0){
            if(X>m-Y){
                mn=m-Y;
                f=3;
            }
            else {
                mn=X;
                f=1;
            }
            xx=X-mn;
            yy=Y+mn;
            for(auto i:xl[0][xx+yy])
                if(!ans[i]) ans[i]=X-x[i]+cnt;
        }
        else if(f==1){
            if(n-X>m-Y){
                mn=m-Y;
                f=2;
            }
            else {
                mn=n-X;
                f=0;
            }
            xx=X+mn;
            yy=Y+mn;
            for(auto i:xl[1][yy-xx+100000])
                if(!ans[i]) ans[i]=x[i]-X+cnt;
        }
        else if(f==2){
            if(n-X>Y){
                mn=Y;
                f=1;
            }
            else {
                mn=n-X;
                f=3;
            }
            xx=X+mn;
            yy=Y-mn;
            for(auto i:xl[0][yy+xx])
                if(!ans[i]) ans[i]=x[i]-X+cnt;
        }
        else {
            if(X>Y){
                mn=Y;
                f=0;
            }
            else {
                mn=X;
                f=2;
            }
            xx=X-mn;
            yy=Y-mn;
            for(auto i:xl[1][yy-xx+100000])
                if(!ans[i]) ans[i]=X-x[i]+cnt;
        }
        X=xx;
        Y=yy;
        cnt+=mn;
        if((X==0&&Y==0)||(X==n&&Y==0)||(X==0&&Y==m)||(X==n&&Y==m)) break;
    }
    for(int i=0;i<k;i++)
        printf("%I64d\n",ans[i]?ans[i]:-1);
    return 0;
}
//D - Dense Subsequence
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
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAX=100010;
int n,m;
char s[MAX];
int v[MAX];
int num[110];
int i,j,t,k;
char b;
void solve(){
    for(i=0; i<n; i++) if(s[i]<b&&!v[i]) num[s[i]-'a']++;
    for(i=0; i<26; i++)
        while(num[i])
        {
            char x=i+'a';
            printf("%c",x);
            num[i]--;
        }
}
int main()
{
    scanf("%d%s",&m,s);
    n=strlen(s);
    int l=0;
    b='a';
    for(i=0; i<n&&i<n-m+1; i++)
    {
        k=0;
        char a='z';
        for(j=i; j<m+i; j++)
        {
            if(s[j]<b)
            {
                k=j;
                break;
            }
            if(s[j]<=a)
            {
                a=s[j];
                k=j;
            }
        }
        if(s[k]>b)
            b=s[k];
        num[s[k]-'a']++;
        v[k]=1;
        i=k;
    }
    solve();
    return 0;
}
