#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 1000;
const int maxm = 9000;
int dp[maxn][maxm],v[maxn][maxm];
vector<int> ans;

int main(){
    memset(dp,0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i=1;i<=900;i++){
        for(int j=1;j<=8100;j++){
            for(int k=1;k<=9;k++){
                int x = i-k,y = j-k*k;
                if(x>=0 && y>=0){
                    if(dp[i][j] > dp[x][y]+1){
                        dp[i][j] = dp[x][y]+1;
                        v[i][j] = k;
                    }
                }
            }
        }
    }
    int s1,s2;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %d",&s1,&s2)){
        if(s1>900 || s2>8100 || dp[s1][s2]==INF){
            puts("No solution");
        }
        else{
            ans.clear();
            int x = s1,y = s2;
            while(x && y){
                ans.push_back(v[x][y]);
                int t = v[x][y];
                x -= t,y -= t*t;
            }
            sort(ans.begin(),ans.end());
            for(auto x : ans){
                printf("%d",x);
            }
            puts("");
        }
    }
    return 0;
}
