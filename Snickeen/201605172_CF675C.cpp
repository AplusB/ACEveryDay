/*
    感谢群“每天一道a+b”中的 Ivan Jobs 巨巨的指点！
	
    首先，最优解肯定是 把环分隔成多个和为0的分组分别处理。 
每一个和为0分组，操作次数是 分组大小-1（可以想一下，取一个位置，其他位置都从远到近靠拢）
算一下，如果分成k个分组，最后操作总数为n-k, 那么k越大，解越忧。
转化为求能分隔成最多的0和连续组（环）
通过求前缀和， 前缀和里出现次数最多的那个次数，就是k的最大值。
得解。
    
    感谢磊巨指点。 
	
    前缀和出现的最大的次数为分组数。
    
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<algorithm> 
#include<stdlib.h>
#include<math.h> 
#include<queue>
#include<stack>
#include<map>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define db double
#define ld long double
#define FIN  freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define CC(a) memset(a,0,sizeof(a))

template<typename T> inline void in(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}

struct TT{
    int a,b,dir;
};TT tt[1];
LL ff[100011],dd[100011],n,m,i,j,k,l,t,s,r,mmax,mmin,num,ans;
LL MOD=1e9+7;
map<LL , int> ma;

int main(){
    in(n);
    repu(i,1,n){
        in(dd[i]);
        ff[i]=ff[i-1]+dd[i];
        k=++ma[ff[i]];
        ans=max(ans,k);
    }
    printf("%I64d\n",n-ans);
    return 0;
}

