#include<bits/stdc++.h>
using namespace std;

const int maxn = 110;
vector<int> edge[maxn];

void init(){
    for(int i=0;i<maxn;i++) edge[i].clear();
}

int siz[maxn];
int ans,k;

void dfs(int st){
    if(siz[st] != -1) return;
    siz[st] = 1;
    for(auto x : edge[st]){
        dfs(x);
        siz[st] += siz[x];
    }
    if(siz[st] == k + 1)
        ans++;
}

int main(){
    int n;
    while(~scanf("%d %d",&n,&k)){
        ans = 0;
        int l,r;
        init();
        for(int i=1;i<n;i++){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
        }
        memset(siz,-1,sizeof(siz));
        for(int i=1;i<=n;i++){
            if(siz[i] == -1) dfs(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}

