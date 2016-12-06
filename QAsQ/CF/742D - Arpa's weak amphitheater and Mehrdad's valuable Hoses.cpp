#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

int arr[maxn];
void init(){
    for(int i = 0 ; i < maxn ; i ++){
        arr[i] = i;
    }
}
int fnd(int x){
    return x == arr[x] ? arr[x] : arr[x] = fnd(arr[x]);
}
void join(int x,int y){
    x = fnd(x),y = fnd(y);
    if(x != y) arr[x] = y;
}

#define LL long long 
LL w[maxn],b[maxn];
LL sw[maxn],sb[maxn];
vector<int> edge[maxn];

LL dp[2][maxn];

int main(){
    int n,m,v;
    scanf("%d %d %d",&n,&m,&v);
    init();
    for(int i = 1; i <= n ; i ++) scanf("%I64d",&w[i]);
    for(int i = 1; i <= n ; i ++) scanf("%I64d",&b[i]);
    int x,y;
    while(m--){
        scanf("%d %d",&x,&y);
        join(x,y);
    }
    memset(sw,0,sizeof(sw));
    memset(sb,0,sizeof(sb));
    for(int i = 1; i <= n ; i ++){
        int to = fnd(i);
        sw[to] += w[i];
        sb[to] += b[i];
        edge[to].push_back(i);
    }
    memset(dp,0,sizeof(dp));
    int yet = 0,st = 1;

    for(int i = 1; i <= n ; i ++){
        if(fnd(i) == i){
            for(int j = 1; j <= v ; j ++)
                dp[st][j] = dp[yet][j];
            for(int j = v; j >= sw[i];j--){
                dp[st][j] = max(dp[st][j],dp[yet][j-sw[i]]+sb[i]);
            }
            for(auto x : edge[i]){
                for(int j = v; j >= w[x];j--){
                    dp[st][j] = max(dp[st][j],dp[yet][j-w[x]]+b[x]);
                }
            }
            st ^= 1,yet ^= 1;
        }
    }
    printf("%I64d\n",dp[yet][v]);
    return 0;
}
