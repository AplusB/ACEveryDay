#include<bits/stdc++.h>
using namespace std;

int val[1<<20];

int gs(string v){
    int ret = 0;
    for(auto x : v)
        ret = ret * 2 + x - '0';
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    memset(val,0,sizeof(val));
    int ord, x;
    string s;
    while(m--){
        cin>>ord;
        if(ord == 1 || ord == 2){
            cin>>x>>s;
            int S = gs(s);
            for(int i = S;i;i=(i-1) & S){
                if(ord == 1) val[i] = x;
                else val[i] ^= x;
            }
            if(ord == 1) val[0] = x;
            else val[0] ^= x;
        }
        else{
            cin>>s;
            int S = gs(s);
            cout<<val[S]<<endl;
        }
    }
    return 0;
}

