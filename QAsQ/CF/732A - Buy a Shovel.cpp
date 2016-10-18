#include<bits/stdc++.h>
using namespace std;

int cal(int k,int x){
    for(int i=1;i<=10;i++){
        if((k*i) % 10 == x || (k*i) % 10 == 0) return i;
    }
    return 10;
}

int main(){
    int k,r;
    cin>>k>>r;
    cout<<cal(k,r)<<endl;
    return 0;
}


