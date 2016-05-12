#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<cstdlib>
#include<cmath>
#define PI 2*asin(1.0)
#define LL long long
#define pb push_back
#define pa pair<int,int>
#define clr(a,b) memset(a,b,sizeof(a))
#define lson lr<<1,l,mid
#define rson lr<<1|1,mid+1,r
#define bug(x) printf("%d++++++++++++++++++++%d\n",x,x)
#define key_value ch[ch[root][1]][0]C:\Program Files\Git\bin
const LL  MOD = 1E9+7;
const LL N = 5e5+15;
const int maxn = 5e5+15;
const int letter = 130;
const LL INF = 1e18;
const double pi=acos(-1.0);
const double eps=1e-10;
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,q,a[maxn],ps[maxn];
int dis[N],vis[N],prime[50000],cnt=0;
vector<int>G[maxn];
inline void init(){
    vis[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&prime[j]*i<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    int x;
    init();
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        ps[i]=x;
        if(x==1){
            G[i].pb(1);
            continue;
        }
        for(int j=1;prime[j]*prime[j]<=x;j++){
            if(x%prime[j]==0){
                G[i].pb(prime[j]);
                while(x%prime[j]==0) x/=prime[j];
            }
        }
        if(x!=1) G[i].pb(x);
    }
    LL sum=0,ans=1,pp;
    int cc,cnt=0;
    while(q--){
        scanf("%d",&x);
        if(ps[x]==1){
            if(!a[x]) sum+=1ll*cnt,cnt++;
            if(a[x]) sum-=1ll*(cnt-1),cnt--;
        }
        else if(!a[x]){
            int p=G[x].size();
            pp=0;
            for(int i=1;i<(1<<p);i++){
                ans=1,cc=0;
                for(int j=0;j<p;j++){
                    if(i&(1<<j)){
                        ans*=G[x][j];
                        cc++;
                    }
                }
                if(cc&1) pp+=dis[ans];
                else pp-=dis[ans];
                dis[ans]++;
            }
            sum+=1ll*(cnt-pp);
            cnt++;
        }
        else {
            int p=G[x].size();
            pp=0;
            for(int i=1;i<(1<<p);i++){
                ans=1,cc=0;
                for(int j=0;j<p;j++){
                    if(i&(1<<j)){
                        ans*=G[x][j];
                        cc++;
                    }
                }
                if(cc&1) pp+=1ll*dis[ans];
                else pp-=1ll*dis[ans];
                dis[ans]--;
            }
            sum-=1ll*(cnt-pp);
            cnt--;
        }
        a[x]=!a[x];
        printf("%I64d\n",sum);
    }
    return 0;
}
/*
10 200000
151790 360570 1 1 123690 162690 1 155208 227488 1
3
10
10
7

*/
