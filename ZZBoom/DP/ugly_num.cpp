//poj 1338
//#include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const LL INF=0x3f3f3f3f;

const int N=1e3+555;

LL dp[N];

void INIT()
{
    LL k,p1,p2,p3,p4;
    int i,j;
    dp[1]=1;
    for(i=2;i<=1500;i++){
        k=INF;
        for(j=1;j<i;j++){
            p1=dp[j]*2;
            p2=dp[j]*3;
            p3=dp[j]*5;
            if(p1>dp[i-1]){
                k=min(k,p1);
            }
            if(p2>dp[i-1]){
                k=min(k,p2);
            }
            if(p3>dp[i-1]){
                k=min(k,p3);
            }
        }
        dp[i]=k;
    }
}
int main()
{
    INIT();
    int n;
    while(~scanf("%d",&n)&&n){
        printf("%lld\n",dp[n]);
    }
}




