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
const LL  MOD = 1000000007;
const LL N = 4e5+15;
const int maxn = 1e6+15;
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
int dfn[N],n,m,w[N],val[N];
int head[N],tot=0,cnt;
int l[N],r[N];
LL ans[N<<2],laz[N<<2];
struct edges{
    int to,next;
}e[N<<1];
inline void addedges(int u,int v){
    e[tot].to=v,e[tot].next=head[u],head[u]=tot++;
}
inline void dfs(int x,int fa){
    dfn[++cnt]=x;
    l[x]=cnt;
    for(int i=head[x];i!=-1;i=e[i].next){
        if(e[i].to==fa) continue;
        dfs(e[i].to,x);
    }
    r[x]=cnt;
}
void pushup(int lr){
    ans[lr]=ans[lr<<1]|ans[lr<<1|1];
}
void pushdown(int lr){
    if(laz[lr]){
        ans[lr<<1]=ans[lr<<1|1]=laz[lr];
        laz[lr<<1]=laz[lr<<1|1]=laz[lr];
        laz[lr]=0;
    }
}
void build(int lr,int l,int r){
    if(l>r) return;
    laz[lr]=0;
    if(l==r){
        ans[lr]=(1LL<<val[l]);
        return;
    }
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(lr);
}
void update(int ll,int rr,int v,int lr,int l,int r){
    if(ll<=l&&r<=rr){
        ans[lr]=(1LL<<v);
        laz[lr]=(1LL<<v);
        return;
    }
    pushdown(lr);
    int mid=(l+r)>>1;
    if(ll<=mid) update(ll,rr,v,lson);
    if(rr>mid) update(ll,rr,v,rson);
    pushup(lr);
}
LL query(int ll,int rr,int lr,int l,int r){
    if(ll<=l&&r<=rr) return ans[lr];
    pushdown(lr);
    int mid=(l+r)>>1;
    LL ans1=0;
    if(ll<=mid) ans1|=query(ll,rr,lson);
    if(rr>mid) ans1|=query(ll,rr,rson);
    pushup(lr);
    return ans1;
}
int main(){
    int id,x,y;
    clr(head,-1),tot=0;
    n=read(),m=read();
    for(int i=1;i<=n;i++) scanf("%d",w+i);
    for(int i=0;i<n-1;i++){
        scanf("%d%d",&x,&y);
        addedges(x,y);
        addedges(y,x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++) val[i]=w[dfn[i]];
    build(1,1,n);
    while(m--){
        scanf("%d%d",&id,&x);
        if(id==1){
            scanf("%d",&y);
            update(l[x],r[x],y,1,1,n);
        }
        else {
            LL vs=query(l[x],r[x],1,1,n);
            int cnt=0;
            while(vs){
                if(vs%2ll) cnt++;
                vs/=2ll;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
