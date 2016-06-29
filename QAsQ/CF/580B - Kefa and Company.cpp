#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 112345;
struct node{
    LL m,s;
    void init(){
        cin>>m>>s;
    }
};

node arr[maxn];
LL sum[maxn];

int main(){
    ios::sync_with_stdio(false);
    int n;
    LL d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        arr[i].init();
    }
    sort(arr+1,arr+1+n,[](node a,node b){return a.m<b.m;});
    sum[0] = 0;
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+arr[i].s;
    }
    LL ans = 0;
    int st = 1;
    for(int ed = 1;ed <= n;ed++){
        while(arr[ed].m - arr[st].m >= d)
           st++;
        ans = max(ans,sum[ed]-sum[st-1]);
    }
   cout<<ans<<endl;
  return 0;
} 
