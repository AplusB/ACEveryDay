//UVALive6827 - Galaxy collision
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
VI g[50010];
map<PII,int>m;
int x[50010],y[50010];
int v[50010];
int cnt[2];
LL dis(LL x,LL y,LL xx,LL yy){
    return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}
void dfs(int u,int s){
    v[u]=1;
    cnt[s]++;
    for(int i=0;i<SZ(g[u]);i++) if(!v[g[u][i]]) dfs(g[u][i],s^1);
}
int main(){
    int n,xx,yy;
    while(cin>>n){
        for(int i=0;i<=n;i++) g[i].clear();
        m.clear();
        memset(v,0,sizeof v);
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
            m[mp(x[i],y[i])]=i;
        }
        map<PII,int>::iterator it;
        PII t;
        for(int i=0;i<n;i++){
            for(int j=-5;j<=5;j++)
            for(int k=-5;k<=5;k++){
                xx=x[i]+j;
                yy=y[i]+k;
                if(dis(xx,yy,x[i],y[i])>25) continue;
                t=mp(xx,yy);
                it=m.find(t);
                if(it!=m.end()) g[i].pb(it->se);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        if(!v[i]){
            cnt[0]=cnt[1]=0;
            dfs(i,0);
            ans+=(cnt[0]>cnt[1]?cnt[1]:cnt[0]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
