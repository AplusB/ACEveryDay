#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

#define LL long long 
int get(LL n){
    LL x = 1378;
    LL ret = 1;
    while(n){
        if(n&1){
            (ret *= x) %= 10;
        }
        (x *= x) %= 10;
        n >>= 1;
    }
    return ret;
}

int main(){
    LL n;
    cin>>n;
    cout<<get(n)<<endl;
    return 0;
}
