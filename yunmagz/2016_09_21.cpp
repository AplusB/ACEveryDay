//AtCoder Regular Contest 061
//C - たくさんの数式 / Many Formulas
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
LL a[15][15];
int main()
{
    string s;
    cin>>s;
    int n=SZ(s);
    for(int i=0;i<n;i++){
        a[i][i]=s[i]-'0';
        for(int j=i+1;j<n;j++)
            a[i][j]=a[i][j-1]*10+s[j]-'0';
    }
    LL ans=0;
    for(int i=0;i<(1<<n-1);i++){
        int p=-1;
        for(int j=0;j<n-1;j++){
            if(i&(1<<j)){
                ans+=a[p+1][j];
                p=j;
            }
        }
        ans+=a[p+1][n-1];
    }
    cout<<ans<<endl;
    return 0;
}
//D - すぬけ君の塗り絵 / Snuke's Coloring
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
map<int,map<int,int> >m;
LL ans[15];
int main()
{
    int h,w,n;
    cin>>h>>w>>n;
    ans[0]=1LL*(h-2)*(w-2);
    while(n--){
        int a,b;
        cin>>a>>b;
        for(int i=a-1;i<=a+1;i++){
            if(i<=0||i>h) continue;
            for(int j=b-1;j<=b+1;j++){
                if(j<=0||j>w) continue;
                int cnt=0,flag=1;
                for(int ii=i-1;ii<=i+1&&flag;ii++){
                    if(ii<=0||ii>h) flag=0;
                    for(int jj=j-1;jj<=j+1&&flag;jj++){
                        if(jj<=0||jj>w) flag=0;
                        if(m[ii][jj]) cnt++;
                    }
                }
                if(!flag) continue;
                ans[cnt]--;
                ans[cnt+1]++;
            }
        }
        m[a][b]=1;
    }
    if(h<3||w<3) memset(ans,0,sizeof ans);
    for(int i=0;i<10;i++) cout<<ans[i]<<endl;
    return 0;
}
