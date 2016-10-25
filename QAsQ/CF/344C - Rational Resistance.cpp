#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
    LL a,b;
    cin>>a>>b;
    LL tim = 0;
    do{
        if(a > b) swap(a,b);
        if(a == 1){
            tim += b,b = 1;
        }
        else{
            tim += b / a;
            b %= a;
        }
    } while(a != 1 || b != 1);
    cout<<tim<<endl;
    return 0;
}
