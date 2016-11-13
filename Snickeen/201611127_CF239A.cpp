#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,y,j,b=0;
    cin>>y>>k>>n;
    j=k-y%k;
    while(j<=n-y){
        cout<<j<<" ";
        j+=k;++b;
    }
    if(b==0) cout<<-1;
}
