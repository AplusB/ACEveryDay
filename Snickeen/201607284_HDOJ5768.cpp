//#include<bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <functional>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef double db;
typedef long double ldb;
#define rep(i,a,b) for(i=a;i<b;i++)
#define repu(i,a,b) for(i=a;i<=b;i++)
#define repd(i,a,b) for(i=a;i>=b;i--)
#define repc(i,a,b,c) for(i=a;i<b;i+=c)
#define repcu(i,a,b,c) for(i=a;i<=b;i+=c)
#define repcd(i,a,b,c) for(i=a;i>=b;i-=c)
#define FIN freopen("input.in","r",stdin)
#define FOUT freopen("output.out","w",stdout)
#define CC(a) memset(a,0,sizeof(a))
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define VI vector<int>
#define VII vector<PII>
#define VLL vector<PLL>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second

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


LL t,n,ans,L,R;
int MOD=1e9+7;
const int maxn = 18;

LL dp[1<<18],fm[18],fr[18],m[maxn],r[maxn];; 

void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b) {d = a, x = 1, y = 0;}
    else
    {
        ex_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
LL ex_crt(LL *m, LL *r, int n)
{
    LL M = m[0], R = r[0], x, y, d;
    for (int i = 1; i <= n; ++i)
    {
        ex_gcd(M, m[i], d, x, y);
        if ((r[i] - R) % d) return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R > 0 ? R : R + M;
}

LL get(LL x,LL y)
{
    LL a,b;
    if(R>=y){
        a=(R-y)/x+1;
    }
    else a=0;
    if(L-1>=y){
        b=(L-1-y)/x+1;
    }
    else b=0;
    return max(a-b,0LL);
}

void solve()
{
    LL i,j,k,res=0,cnt,tmp,num;
    CC(fm);CC(fr);fm[0]=7;fr[0]=0;
    ans=get(7,0);
    
    for(i=1;i<(1<<n);i++){
        cnt=0;tmp=1ll;
        for(j=1;j<=n;j++){
            if(i & (1<<j>>1)){
                fm[++cnt]=m[j];
                fr[cnt]=r[j];
//                cnt++;
                tmp*=m[j];
            }
        }
        num=ex_crt(fm,fr,cnt);
//        printf("%I64d %I64d %I64d ",cnt,tmp,num);
        num=get(tmp*7,num);
        if(cnt&1)ans-=num;
        else ans+=num;
//        printf("%I64d %I64d\n",num,ans);
    }
    
}

int main()
{
    LL ca=0,i,j,k;
    scanf("%I64d",&t);
    while (t--)
    {
        scanf("%I64d%I64d%I64d",&n,&L,&R);
        for (i = 1; i <= n; ++i)
            scanf("%I64d%I64d", &m[i], &r[i]);
        solve();
        printf("Case #%I64d: %I64d\n",++ca,ans);
    }
    return 0;
}
