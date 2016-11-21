#include<bits/stdc++.h>
using namespace std;

#define LL long long 

LL INFF = 2000000000ll;

int main(){
    ios::sync_with_stdio(false);
    LL ma = -INFF, mi = INFF;
    int n;
    cin>>n;
    LL x;
    string ope,yo;
    for(int i = 0 ; i < n ; i ++){
        cin>>ope>>x>>yo;
        if(ope == ">") ope = ">=", x++;
        if(ope == "<") ope = "<=", x--;
        if(yo == "N"){
            if(ope == ">="){
                x--,ope = "<=";
            }
            else{
                x++,ope = ">=";
            }
        }
        if(ope == ">=") ma = max(ma,x);
        if(ope == "<=") mi = min(mi,x);
    }
    if(ma > mi) cout<<"Impossible"<<endl;
    else cout<<ma<<endl;
    return 0;
}
