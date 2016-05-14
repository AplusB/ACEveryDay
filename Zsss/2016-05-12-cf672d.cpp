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
const LL N = 5e5+15;
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
int n,k,a[N];
LL check1(int v){
    LL ans=0;
    for(int i=0;i<n;i++){
        if(a[i]<v) ans+=1ll*(v-a[i]);
    }
    return ans;
}
LL check2(int v){
    LL ans=0;
    for(int i=0;i<n;i++){
        if(a[i]>v) ans+=1ll*(a[i]-v);
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    LL sum=0;
    for(int i=0;i<n;i++)scanf("%d",a+i),sum+=1ll*a[i];
    int l=1,r=(int)(1e9),mid;
    int lf,rf;
    while(l+1<r){
        mid=(l+r)>>1;
        LL vs=check1(mid);
        if(vs<=k)l=mid;
        else r=mid;
    }
    lf=l;
    l=1,r=(int)1e9;
    while(l+1<r){
        mid=(l+r)>>1;
        LL vs=check2(mid);
        if(vs<=k)r=mid;
        else l=mid;
    }
    rf=r;
    if(rf-lf>0) printf("%d\n",rf-lf);
    else printf("%d\n",sum%n?1:0);
    return 0;
}
