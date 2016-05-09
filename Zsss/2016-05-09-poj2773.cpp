
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
const LL N = 1e3+15;
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
int x,k;
int vis[N],prime[N],cnt=0;
int ps[30],num;
void init(){
    vis[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<N;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
}
LL check(LL x){
    ///[1,x]
    LL sum=x,ans=1,res=0;
    int cc=0;
    for(int i=1;i<(1<<num);i++){
        cc=0;
        LL ans=1;
        for(int j=0;j<num;j++){
            if(i&(1<<j)){
                cc++;
                ans*=1ll*ps[j];
            }
        }
        if(cc%2) res+=x/ans;
        else res-=x/ans;
    }
    return sum-res;
}
int main(){
    init();
    while(scanf("%d%d",&x,&k)!=EOF){
        num=0;
        for(int i=1;i<=cnt;i++){
            if(x%prime[i]==0){
                while(x%prime[i]==0) x/=prime[i];
                ps[num++]=prime[i];
            }
        }
        if(x!=1) ps[num++]=x;
        LL l=1,r=INF,mid;
        LL flag;
        while(l<r){
            mid=(l+r)/2;
            flag=check(mid);
            if(flag<k) l=mid+1;
            else r=mid;
        }
        printf("%I64d\n",r);
    }
    return 0;
}
/*
12 4
*/
