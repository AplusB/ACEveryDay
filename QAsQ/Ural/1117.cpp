#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define LL long long

bool jud(LL n){
    n--;
    if(n <= 2) return false;
    return n % 4 == 0;
}

LL cal(LL n){
    LL ret = 1-n;
    while(n>1){
        ret += n-1;
        n = n/2 + jud(n);
    }
    return ret;
}

int main(){
    LL l,r;
    while(~scanf("%lld %lld",&l,&r)){
        if(l>r) swap(l,r);
        printf("%lld\n",cal(r)-cal(l));
    }
    return 0;
}
