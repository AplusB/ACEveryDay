#include<bits/stdc++.h>
using namespace std;

int main(){
    int can = 0;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        can += x == 0;
    }
    if((n != 1 && can == 1) || (n==1 && can == 0)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}


