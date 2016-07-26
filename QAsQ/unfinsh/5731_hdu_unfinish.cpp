#include<bits/stdc++.h>
using namespace std;

#define LL long long

const int bit = 17, maxn = 1<<bit;
const int mod = 1000000007;
LL any[bit][bit];
LL dp[bit][bit][maxn];

void cdp(int m){
    for(int i=1;i<bit;i++){
        for(int j=1;j<=m;j++){
            LL *bdp = j==1? dp[i-1][m] : dp[i][j-1];

}

void init(){
    for(int j=1;j<bit;j++){
        cdp(j);
        for(int i=1;i<bit;i++){
            any[i][j] = dp[i][j][(1<<j)-1];
        }
    }
}


