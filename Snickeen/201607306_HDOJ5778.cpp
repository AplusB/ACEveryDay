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


LL t,n,m,ans;
LL MOD=1e9+7;
const LL maxn=100005;
LL pr[maxn/10];
bitset<maxn> prime;

void getprime()
{
    LL i,j,k,l;
    for(i=2;i<maxn;i++){
        if(!prime[i]){
            pr[++pr[0]]=i;
            for(j=i+i;j<maxn;j+=i)prime[j]=1;
        }
    }
}

LL check(LL x){
    LL i,j,k,l;
    for(i=1;i<=pr[0]&&pr[i]<=x;i++){
        if(x%pr[i]==0){
            x/=pr[i];
            if(x%pr[i]==0){
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    getprime();
    LL ca=0,i,j,k,l,r;
    gn(t);
    while(t--){
        gn(n);
        if(n==1){
            puts("3");
            continue;
        }
        if(n==2){
            puts("2");
            continue;
        }
        if(n==3){
            puts("1");
            continue;
        }
        
        m=sqrt(n);
        if(m*m==n&&check(m)){
            printf("0\n");
            continue;
        }
        for(i=m+1;i<1e18;i++){
            if(check(i)){
                r=i*i;
                break;
            }
        }
        for(i=m;i;i--){
            if(check(i)){
                l=i*i;
                break;
            }
        }
        ans=min(abs(n-l),abs(r-n));
        printf("%d\n",ans);
    }
    return 0;
}
