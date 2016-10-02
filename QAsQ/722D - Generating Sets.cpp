#include<bits/stdc++.h>
using namespace std;

#define LL long long 

const int maxn = 512345;
LL inp[maxn];

int n;
set<LL> S;
vector<LL> tem;
bool check(LL k){
    S.clear();
    tem.clear();
    for(int i=0;i<n;i++){
        LL tp = inp[i];
        while(tp > k) tp/=2;
        while(S.find(tp) != S.end()) tp/=2;
        if(tp == 0) return false;
        tem.push_back(tp);
        S.insert(tp);
    }
    return true;
}

vector<LL> ans;

void solve(){
    LL st = n,ed = n;
    for(int i=0;i<n;i++) ed = max(ed,inp[i]);
    LL best = -1;
    while(st <= ed){
        LL mid = (st + ed) / 2;
        if(check(mid)){
            ans = tem;
            ed = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>inp[i];
    solve();
    for(int i=0;i<n;i++){
        if(!i) cout<<ans[i];
        else cout<<" "<<ans[i];
    }
    return 0;
}

