#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    int ret = 0;
    int n,l,r;
    cin>>n;
    while(n--){
        cin>>l >> r;
        ret += r-l>=2;
    }
    cout<<ret<<endl;
    return 0;
}
