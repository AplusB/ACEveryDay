#include<bits/stdc++.h>
using namespace std;

const int maxn = 312345;
set<int> S;

int ans[maxn];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++) S.insert(i);
    memset(ans,0,sizeof(ans));
    int l,r,x;
    while(m--){
        scanf("%d %d %d",&l,&r,&x);
        set<int>::iterator it = S.lower_bound(l);
        while(it != S.end() && *it <= r){
            ans[*it] = x;
            int v = *it;
            it++;
            S.erase(v);
        }
        S.insert(x);
        ans[x] = 0;
    }
    for(int i = 1;i <= n;i++){
        printf(i<n?"%d ":"%d\n",ans[i]);
    }
    return 0;
}
