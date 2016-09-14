#include<bits/stdc++.h>
using namespace std;

#define LL long long 

map<int,int> M;

bool judge(){
    if(M.size() <= 2) return true;
    if(M.size() > 3 ) return false;
    vector<LL> v;
    for(auto x : M){
        v.push_back(x.first);
    }
    return v[0] + v[2] == v[1] * 2;
}

int main(){
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        M[x]++;
    }
    cout<<(judge() ? "YES":"NO")<<endl;
    return 0;
}


