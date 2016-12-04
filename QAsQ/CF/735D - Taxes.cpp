#include<bits/stdc++.h>
using namespace std;

#define LL long long 
bool check(LL x){
    for(LL i = 2; i * i <= x ; i ++){
        if(x % i == 0) return false; 
    }
    return true;
}

int getans(LL x){
    if(x <= 3) return 1;
    if(x & 1){
        if(check(x)) return 1;
        if(check(x-2)) return 2;
        return 3;
    }
    else{
        return 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    LL x;
    cin>>x;
    cout<<getans(x)<<endl;
    return 0;
}
