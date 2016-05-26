#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 16;
const int INF = 0x3f3f3f3f;

int dp[1<<maxn],pre[1<<maxn];
int dl[maxn],last[maxn];

char arr[maxn][110];
int n;

int slast(int S){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(S&(1<<i)) ret += last[i];
    }
    return ret;
}

int dfs(int S){
    if(dp[S] != INF){
        return dp[S];
    }
    int sumer = slast(S);
    for(int i=0;i<n;i++){
        if(S&(1<<i)){
            int ndp = dfs(S-(1<<i)) + max(0,sumer-dl[i]);
            if(ndp <= dp[S]){
                dp[S] = ndp,pre[S] = i;
            }
        }
    }
    return dp[S];
}

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%s %d %d",arr[i],&dl[i],&last[i]);
        }
        int all = (1<<n)-1;
        memset(dp,0x3f,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        dp[0] = 0;
        printf("%d\n",dfs(all));
        stack<int> S;
        while(all){
            S.push(pre[all]);
            all -= (1<<pre[all]);
        }
        while(S.empty()==false){
            printf("%s\n",arr[S.top()]);
            S.pop();
        }
    }
    return 0;
}
