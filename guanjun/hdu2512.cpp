/* ***********************************************
Author        :guanjun
Created Time  :2016/6/16 20:30:58
File Name     :hdu2512.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 1000
#define INF 0x3f3f3f3f
#define maxn 10000
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
    int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
    }
};

bool cmp(int a,int b){
    return a>b;
}
int dp[2010][2010];
int n;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        cle(dp);
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j]*j;
                dp[i][j]%=mod;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=dp[n][i];
        cout<<ans%mod<<endl;
    }
    return 0;
}
