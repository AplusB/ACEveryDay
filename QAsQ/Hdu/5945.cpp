#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
int dp[maxn];
deque<int> Q;

int calans(int x,int k,int t){
    if(t == 0){
        int ret = 0;
        while(x != 1){
            x /= k;
            ret++;
        }
        return ret;
    }
    while(Q.empty()==false) Q.pop_back();

    dp[1] = 0;
    Q.push_front(0);
    for(int i = 2;i <= x;i++){
        dp[i] = Q.front() + 1;
        if(i % k == 0){
            dp[i] = min(dp[i],dp[i / k]+1);
        }
        if(i > t && Q.front() == dp[i-t]) Q.pop_front();
        while(Q.empty()==false && Q.back() > dp[i])
            Q.pop_back();
        Q.push_back(dp[i]);
    }
    return dp[x];
}

int main(){  
    int T;  
    scanf("%d",&T);  
    int x,k,t;
    while(T-- && ~scanf("%d %d %d",&x,&k,&t)){  
        printf("%d\n",calans(x,k,t));
    }  
    return 0;  
}  
