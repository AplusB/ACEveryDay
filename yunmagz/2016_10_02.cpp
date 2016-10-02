//Intel Code Challenge Elimination Round (Div.1 + Div.2, combined)
//A - Broken Clock
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
int n,mx,g[10];
char s[10];
bool check(int a,int b,int c,int d){
    int h=a*10+b;
    int m=c*10+d;
    if(n==12){
        if(h>=1&&h<=12&&m>=0&&m<60) return 1;
        return 0;
    }
    else {
        if(h>=0&&h<24&&m>=0&&m<60) return 1;
        return 0;
    }
}
int main()
{
    mx=inf;
    cin>>n;
    scanf("%s",s);
    s[0]-='0';s[1]-='0';s[3]-='0';s[4]-='0';
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                for(int l=0;l<10;l++){
                    if(check(i,j,k,l)){
                        int sum=(i!=s[0])+(j!=s[1])+(k!=s[3])+(l!=s[4]);
                        if(sum<mx){
                            mx=sum;
                            g[0]=i;
                            g[1]=j;
                            g[2]=k;
                            g[3]=l;
                        }
                    }
                }
            }
        }
    }
    printf("%d%d:%d%d\n",g[0],g[1],g[2],g[3]);
    return 0;
}
//B - Verse Pattern
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
int a[110];
int main()
{
    string s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    getchar();
    for(int i=0;i<n;i++){
        getline(cin,s);
        int m=SZ(s);
        int cnt=0;
        for(int j=0;j<m;j++) if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='y') cnt++;
        if(cnt!=a[i]) return 0*puts("NO");
    }
    puts("YES");
    return 0;
}
//C - Destroying Array
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

LL a[100005],b[100005],pre[100005],ans1[100005],ans2[100005],x[100005],s[100005];
set<LL>ss;
map<LL,int>pp;
int main()
{
    set<LL>::iterator it;
    int n,top=0,l,r;
    scanf("%d",&n);
    LL ans=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        pre[i]=pre[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
        a[x[i]]=i;
    }
    for(int i=n;i;i--)
	{
		while(top&&a[s[top]]>a[i])top--;
		ans1[i]=s[top]?s[top]:n+1;
		s[++top]=i;
	}
    reverse(a+1,a+n+1);
    top=0;
    for(int i=n;i;i--)
	{
		while(top&&a[s[top]]>a[i])top--;
		ans2[i]=s[top]?n-s[top]+1:0;
		s[++top]=i;
	}
    reverse(a+1,a+n+1);
    reverse(ans2+1,ans2+n+1);
    ss.insert(pre[n]);
    pp[pre[n]]++;
    for(int i=1;i<n;i++){
        int y=x[i];
        l=ans2[y];
        r=ans1[y];
        pp[pre[r-1]-pre[l]]--;
        if(pp[pre[r-1]-pre[l]]==0) ss.erase(pre[r-1]-pre[l]);
        if(pre[y-1]-pre[l]){
            if(!pp[pre[y-1]-pre[l]])
                ss.insert(pre[y-1]-pre[l]);
            pp[pre[y-1]-pre[l]]++;
        }
        if(pre[r-1]-pre[y]){
            if(!pp[pre[r-1]-pre[y]])
                ss.insert(pre[r-1]-pre[y]);
            pp[pre[r-1]-pre[y]]++;
        }
        it=ss.end();
        it--;
        printf("%I64d\n",*it);
    }
    puts("0");
    return 0;
}
//D - Generating Sets
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
int a[50010],n,tmp[50010];
map<int,bool>vis;
bool f(int mid)
{
    vis.clear();
    for(int i = 1; i <= n; ++i)
    {
        tmp[i] = a[i];
        while(tmp[i] > mid)
            tmp[i] /= 2;
        if(tmp[i] == 0)
            return 0;
        while(tmp[i] && vis.find(tmp[i]) != vis.end())
            tmp[i] >>= 1;
        if(tmp[i] == 0)
            return 0;
        vis[ tmp[i] ] = 1;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=1e9;
    int ans=0;
    while(l<=r){
        int mid=(l+r)>>1;
        if(f(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    f(ans);
    for(int i=1;i<=n;i++) printf("%d ",tmp[i]);
    return 0;
}
