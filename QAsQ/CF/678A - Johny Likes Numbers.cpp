#include<iostream>
using namespace std;
#define LL long long  
int main(){
    LL n,k;
    cin>>n>>k;
    LL x = n+1;
    if(x%k) x = (x/k+1)*k;
    cout<<x<<endl;
    return 0;
}
