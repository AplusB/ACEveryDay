//hihocoder 1364 奖券兑换
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
#define mem(name,value) memset(name,value,sizeof(name))
#pragma comment(linker, "/STACK:102400000,102400000")
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=100100,inf=0x3f3f3f3f;

int ma[15][15];
int dp[maxn];
int main(){
    int n,m;
    cin>>n>>m;
    mem(ma,0);
    for(int i=0;i<n;i++){
        int p,w;
        scanf("%d%d",&w,&p);
        ma[w][p]++;
    }
    mem(dp,0);
    int maxn=0;
    for(int W=1;W<=10;W++){
        for(int P=1;P<=10;P++){
            int k=ma[W][P];
            pair<int,int> a=mp(W,P);
            int ret=1;
            while(ret<=k){
                k-=ret;
                for(int i=m;i>=ret*a.first;i--){
                    if(dp[i-ret*a.first]||i==ret*a.first){
                        dp[i]=max(dp[i],dp[i-ret*a.first]+ret*a.second);
                        maxn=max(maxn,dp[i]);
                    }
                }
                ret*=2;
            }
            if(k){
                for(int i=m;i>=k*a.first;i--){
                    if(dp[i-k*a.first]||i==k*a.first){
                        dp[i]=max(dp[i],dp[i-k*a.first]+k*a.second);
                        maxn=max(maxn,dp[i]);
                    }
                }
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}
