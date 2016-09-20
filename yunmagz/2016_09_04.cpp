//poj3904 Sky Code
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int prime[10010],b[10010],c[10010];
void gao(int n){
    int cnt=0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) prime[cnt++]=i;
        while(n%i==0) n/=i;
    }
    if(n>1) prime[cnt++]=n;
    for(int i=1;i<(1<<cnt);i++){
        int m=1,ct=0;
        for(int j=0;j<cnt;j++){
            if(i&(1<<j)){
                m*=prime[j];
                ct++;
            }
        }
        b[m]++;
        c[m]=ct;
    }
}
LL cal(int x){
    return 1LL*x*(x-1)*(x-2)*(x-3)/24;
}
int main()
{
    int n,x;
    while(~scanf("%d",&n)){
        memset(b,0,sizeof b);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            gao(x);
        }
        LL ans=0;
        for(int i=0;i<=10000;i++){
            if(b[i]){
                if(c[i]&1) ans+=cal(b[i]);
                else ans-=cal(b[i]);
            }
        }
        printf("%lld\n",cal(n)-ans);
    }
    return 0;
}
