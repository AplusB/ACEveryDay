#include<bits/stdc++.h>
using namespace std;

const int maxn = 112;
int ind[maxn],arr[maxn];

bool check(int n){
    for(int i = 1; i <= n ; i ++){
        if(ind[i] != 1) return false;
    }
    return true;
}

#define LL long long 

LL cal(int n){
    memset(ind,0,sizeof(ind));
    LL ret = 1;
    for(int i = 1; i <= n ; i ++){
        if(ind[i] == 0){
            int cnt = 1;
            ind[i] = 1;
            int st = arr[i];
            while(ind[st] == 0){
                cnt++;
                ind[st] = 1;
                st = arr[st];
            }
            ret = ret / __gcd(ret,cnt * 1ll) * cnt;
        }
    }
    if( ( ret & 1) == 0) ret /= 2;
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    memset(ind,0,sizeof(ind));
    for(int i = 1; i <= n; i ++){
        scanf("%d",&arr[i]);
        ind[arr[i]]++;
    }
    if(check(n) == false){
        puts("-1");
    }
    else{
        printf("%I64d\n",cal(n));
    }
    return 0;
}


