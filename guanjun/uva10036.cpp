/* ***********************************************
Author        :guanjun
Created Time  :2016/9/6 15:25:54
File Name     :uva10036.cpp
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
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
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
int dp[maxn][100];
int a[maxn];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t,n,k;
    cin>>t;
    while(t--){
        scanf("%i %i",&n,&k);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]),a[i]=abs(a[i]%k);
        cle(dp);
        dp[1][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<k;j++){
                if(dp[i][j]){
                    dp[i+1][(j-a[i]+k)%k]=1;
                    dp[i+1][(j+a[i])%k]=1;
                }
            }
        }
        if(dp[n+1][0])puts("Divisible");  
        else puts("Not divisible"); 
    }
    return 0;
}
