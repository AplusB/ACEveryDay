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
const LL N = 1e5+15;
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
int n,m,b[N],vis[N];
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        clr(b,0),clr(vis,0);
        int x,cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i*i<=m;i++){
            if(m%i==0){
                b[cnt++]=i;
                if(i!=1&&i*i!=m) b[cnt++]=m/i;
            }
        }
        sort(b,b+cnt);
        for(int i=0;i<n;i++){
            scanf("%d",&x),x%=m;
            if(x!=0){
                x=gcd(x,m);
                for(int j=0;j<cnt;j++) {
                    if(b[j]%x==0) vis[j]=1;
                }
            }
        }
        LL sum=0;
        for(int i=0;i<cnt;i++){
            if(vis[i]){
                int t=(m-1)/b[i];
                sum+=(LL)t*(t+1)/2*b[i]*vis[i];
                for(int j=i+1;j<cnt;j++){
                    if(b[j]%b[i]==0) vis[j]-=vis[i];
                }
            }
        }
        printf("Case #%d: %I64d\n",++cas,sum);
    }
    return 0;
}
