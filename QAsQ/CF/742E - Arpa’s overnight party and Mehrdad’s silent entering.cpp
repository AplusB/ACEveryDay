#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int l[maxn],r[maxn];
vector<int>edge[maxn * 2];

int v[maxn * 2];

void dfs(int st,int w){
    v[st] = w;
    for(auto x : edge[st]){
        if(v[x] == -1) dfs(x,w ^ 1);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d %d",&l[i],&r[i]);
        edge[l[i]].push_back(r[i]); 
        edge[r[i]].push_back(l[i]); 
    }
    memset(v,-1,sizeof(v));
    for(int i = 1; i <= n ; i ++){
        edge[i*2].push_back(i*2-1);
        edge[i*2-1].push_back(i*2);
    }
    for(int i = 1;i <= 2 * n ; i ++){
        if(v[i] == -1) dfs(i,0);
    }
    for(int i = 0;i < n ; i ++){
        printf("%d %d\n",v[l[i]]+1,v[r[i]]+1);
    }
    return 0;
}
