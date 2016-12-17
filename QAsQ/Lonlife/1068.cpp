#include<bits/stdc++.h>
using namespace std;
int geter(int n){
    if(n % 3 == 0) return n / 3;
    return n;
}
int main(){
    int T,n;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        printf("%d\n",geter(n));
    }
    return 0;
}
