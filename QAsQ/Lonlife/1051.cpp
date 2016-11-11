#include<bits/stdc++.h>
using namespace std;

bool judge(int n){
    return n % 4 == 0 || n % 4 == 1;
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        puts(judge(n) ? "yes":"no");
    }
    return 0;
}
