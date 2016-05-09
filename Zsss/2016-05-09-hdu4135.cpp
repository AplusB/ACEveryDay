
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
const LL N = 3e4+5000;
const int maxn = 5e5+15;
const int letter = 130;
const int INF = 1e17;
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
LL a,b;
int x;
int vis[N],cnt=0;
int prime[10000],ps[32];
void init(){
    vis[1]=1;
    for(int i=2;i<N;i++){
        if(!vis[i]) prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<N;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int main(){
    init();
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%d",&a,&b,&x);
        int num=0;
        for(int i=1;i<=cnt;i++){
            if(x%prime[i]==0){
                while(x%prime[i]==0){
                    x/=prime[i];
                }
                ps[num++]=prime[i];
            }
        }
        if(x!=1) ps[num++]=x;
        LL sum=b-a+1ll;
        LL tt=0;
        for(int i=1;i<(1<<num);i++){
            int cc=0;
            LL ans=1;
            for(int j=0;j<num;j++){
                if(i&(1<<j)){
                    cc++;
                    ans*=1ll*ps[j];
                }
            }
            if(cc&1) tt=tt+(b/ans-(a-1)/ans);
            else tt=tt-(b/ans-(a-1)/ans);
        }
        printf("Case #%d: %I64d\n",++cas,sum-tt);
    }
    return 0;
}
/*
100
3 15 12

*/
