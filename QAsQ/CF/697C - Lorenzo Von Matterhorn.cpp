#include<bits/stdc++.h>
using namespace std;
#define LL long long

map<LL,LL> M;

void upd(LL l,LL r,LL v){
    while(abs(l-r) >= 1){
        if(l<r) swap(l,r);
        M[l]+=v,l>>=1;
    }
}

LL que(LL l,LL r){
    LL ret = 0;
    while(abs(l-r) >= 1){
        if(l<r) swap(l,r);
        ret += M[l];
        l>>=1;
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    int ord;
    LL l,r,v;
    while(n--){
        cin>>ord>>l>>r;
        if(ord == 1){
            cin>>v;
            upd(l,r,v);
        }
        else{
            cout<<que(l,r)<<endl;
        }
    }
    return 0;
}
