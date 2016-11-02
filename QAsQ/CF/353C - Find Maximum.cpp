#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int arr[maxn],num[maxn];
char inp[maxn];

int dp[maxn][2];

int dfs(int pos,int bnd){
    if(pos < 0) return 0;
    int & ndp = dp[pos][bnd];
    if(~ndp) return ndp;
    ndp = 0;
    int bound = bnd ? num[pos] : 1;
    for(int i = 0 ; i <= bound;i++){
        ndp = max(ndp,arr[pos] * i + dfs(pos-1,bnd && i == bound));
    }
    return ndp; 
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n; i ++){
        scanf("%d",&arr[i]);
    }
    scanf("%s",inp);
    for(int i = 0 ; i < n;i++){
        num[i] = inp[i] - '0';
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(n-1,true));
    return 0;
}

