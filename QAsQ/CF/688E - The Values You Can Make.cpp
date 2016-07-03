#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 512;

bool dp[maxn][maxn][maxn];
int arr[maxn];

int main(){
    int n,k;
    cin>>n>>k;
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=true;
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int s=0;s<=k;s++){
            for(int t=0;t<=k;t++){
                dp[i][s][t] = ((s>=arr[i]) && dp[i-1][s-arr[i]][t])
                            ||((t>=arr[i]) && dp[i-1][s][t-arr[i]])
                            || dp[i-1][s][t];
            }
        }
    }
    vector<int> ans;
    for(int i=0;i<=k;i++){
        if(dp[n][i][k-i]){
            ans.push_back(i);
            ans.push_back(k-i);
        }
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++){
        printf(i<ans.size()-1?"%d ":"%d\n",ans[i]);
    }
    return 0;
}


