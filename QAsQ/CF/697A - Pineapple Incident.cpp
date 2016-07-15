#include<bits/stdc++.h>
using namespace std;
#define LL long long

bool jud(int t,int s,int x){
    if(x < t) return false;
    if(x == t) return true;
    if(x == t + 1) return false;
    x -= t;
    return x % s <=  1;
}

int main(){
    int t,x,s;
    cin>>t>>s>>x;
    puts(jud(t,s,x)?"YES":"NO");
    return 0;
}
