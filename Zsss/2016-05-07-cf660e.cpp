/*
借鉴博客：http://blog.csdn.net/yukizzz/article/details/51132165
死都不会化解
*/
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
const LL N = 2e3+15;
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
int n,m;
LL mpow(LL a,LL k){
    LL ans=1;
    while(k){
        if(k&1) ans=ans*a%MOD;
        a=a*a%MOD;
        k=k/2;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&m);
    LL sum=mpow(1ll*m,1ll*n);
    for(int i=1;i<=n;i++){
        sum=(sum+mpow(1ll*m,n-i+1)*mpow(2ll*m-1,i-1)%MOD)%MOD;
    }
    printf("%I64d\n",sum);
    return 0;
}
