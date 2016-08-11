//Codeforces Round #365 (Div. 2)
//B - Mishka and trip 
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
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int a[100010],v[100010],b[100010];
LL pre[100010];
int main()
{
    int n,m;
    cin>>n>>m;
    LL sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    a[0]=a[n];
    for(int i=1;i<=m;i++){
        scanf("%d",&b[i]);
        v[b[i]]=1;
        if(b[i]==n) v[0]=1;
        pre[i+1]=a[b[i]]+pre[i];
    }
    sum-=pre[m+1];
    LL ans=0,lst=0;
    for(int i=1;i<=m;i++){
        ans+=a[b[i]]*(sum+pre[i]);
    }
    for(int i=0;i<n;i++)
        if(!v[i] && !v[i+1]) ans+=a[i]*a[i+1];
    cout<<ans<<endl;
    return 0;
}
