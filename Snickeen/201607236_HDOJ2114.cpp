/*
    题意：计算[1,n]的立方和的最后四位，用0补齐。
    思路1：立方和公式，取模。
    思路2：循环节
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T>inline void gn(T &x){
    x=0;T f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
template<typename T>inline void gt(T x){
    if(!x)return;
    gt(x/10);putchar(x%10+'0');
}

int n,m,k,ans;
int MOD=1e9+7;
int ff[10011];

int main()
{
    //FIN;FOUT;
    int i,j,k,l,r;
    for(i=1;i<=10000;i++){
        ff[i]=i*i%10000*i%10000;
        ff[i]+=ff[i-1];
        ff[i]%=10000;
    }
    while(~scanf("%d",&n)){
        l=n/10000;r=n%10000;
        ans=l*ff[10000]+ff[r];
        printf("%04d\n",ans%10000);
    }
    return 0;
}
