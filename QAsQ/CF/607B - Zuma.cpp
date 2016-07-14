#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 550;
int arr[maxn];
int dp[maxn][maxn];

int dfs(int st,int ed){
    int & ndp = dp[st][ed];
    if(ndp != -1) return ndp;
    if(st >= ed) return ndp = 1;
    ndp = ed - st + 1;
    for(int i = st;i<ed;i++)
        ndp = min(ndp,dfs(st,i)+dfs(i+1,ed));
    if(arr[st] == arr[ed])
        ndp = min(ndp,dfs(st+1,ed-1));
    return ndp;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(1,n));
    return 0;
}



