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
const LL N = 16000+15;
const int maxn = 8e3+15;
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
int n;
bool vis[maxn][maxn];
int ans[N<<2];
struct node{
    int x,yl,yr;
    bool operator < (const node &p)const{
        return x<p.x;
    }
}a[maxn];
void pushup(int lr){
    ans[lr]=(ans[lr<<1]==ans[lr<<1|1]?ans[lr<<1]:0);
}
void pushdown(int lr){
    if(ans[lr]){
        ans[lr<<1]=ans[lr<<1|1]=ans[lr];
        ans[lr]=0;
        return;
    }
}
inline void update(int ll,int rr,int v,int lr,int l,int r){
    if(ll<=l&&r<=rr){
        ans[lr]=v;
        return;
    }
    pushdown(lr);
    int mid=(l+r)>>1;
    if(ll<=mid) update(ll,rr,v,lson);
    if(rr>mid)  update(ll,rr,v,rson);
    pushup(lr);
}
inline void query(int ll,int rr,int v,int lr,int l,int r){
    if(ans[lr]){
        vis[ans[lr]][v]=1;
        return;
    }
    if(l==r) return;
   /// pushdown(lr);
    int mid=(l+r)>>1;
    if(ll<=mid) query(ll,rr,v,lson);
    if(rr>mid) query(ll,rr,v,rson);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        clr(vis,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i].yl,&a[i].yr,&a[i].x);
        }
        sort(a+1,a+n+1);
        clr(ans,0);
        for(int i=1;i<=n;i++){
            query(a[i].yl*2,a[i].yr*2,i,1,0,N);
            update(a[i].yl*2,a[i].yr*2,i,1,0,N);
        }
        LL sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(vis[i][j]){
                    for(int k=j+1;k<=n;k++){
                        if(vis[i][k]&&vis[j][k]) sum++;
                    }
                }
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
