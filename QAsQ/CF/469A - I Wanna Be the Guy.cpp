#include<bits/stdc++.h>
using namespace std;
#define LL long long 

set<int> S;

void inser(){
    int n;
    cin>>n;
    int x;
    while(n--){
        cin>>x;
        S.insert(x);
    }
}

int main(){
    int n;
    cin>>n;
    inser();
    inser();
    puts(S.size()==n?"I become the guy.":"Oh, my keyboard!");
    return 0;
}
    
