#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int main(){
    int n,k;
    cin>>n>>k;
    if(n==1 && k==10){
        cout<<"-1";
    }
    else{
        if(n == 1){
            cout<<k<<endl;
        }
        else{
            int lef = 1;
            cout<<"1";
            for(int i=0;i<n-2;i++){
                cout<<"0";
                lef = lef * 10 % k;
            }
            lef = lef * 10 % k;
            if(k - lef == 10) lef = 10;
            cout<<k-lef<<endl;
        }
    }
    return 0;
}
        

