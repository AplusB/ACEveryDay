//Educational Codeforces Round 10
//C - Foe Pairs
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
const int maxn = 3e5+7;

int p[maxn],t[maxn];
int c[maxn];
int main()
{
    int x,y,n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        t[p[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        int a = 0,b = 0;
        a=max(t[x],t[y]),b=min(t[x],t[y]);
        c[a]=max(c[a],b);
    }
    LL ans = 0;
    int l = 0;
    for(int i=1;i<=n;i++)
    {
        l=max(c[i],l);
        ans+=i-l;
    }
    cout<<ans<<endl;
}
