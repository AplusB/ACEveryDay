#include<bits/stdc++.h>
using namespace std;

const int maxn = 2123456;
const int INF = 0x3f3f3f3f;

int sum[maxn];

bool check(int ma,int d,int k,int n){
    int hav = 0;
    for(int i = d ; i <= ma;i+=d){
        hav += sum[i+k] - sum[i-1];
    }
    return hav == n;
}

int main(){
    int n,k;
    int x;
    scanf("%d %d",&n,&k);
    memset(sum,0,sizeof(sum));
    int ma = 0,mi = INF;
    for(int i = 0 ; i < n;i++){
        scanf("%d",&x);
        sum[x]++;
        ma = max(ma,x);
        mi = min(mi,x);
    }
    for(int i = 1 ; i < maxn;i++){
        sum[i] += sum[i-1];
    }
    int ans = k;
    for(int i = k + 1;i <= mi;i++){
        if(check(ma,i,k,n)) ans = i;
    }
    if(ans > mi) ans = mi;
    printf("%d\n",ans);
    return 0;
}

