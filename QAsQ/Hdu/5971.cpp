#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

vector<int> edge[maxn];

int g[maxn],b[maxn];
int color[maxn];
int gb[maxn];

bool dfs(int st,int fa,int cor){
    color[st] = cor;
    for(auto x : edge[st]){
        if(x == fa) continue;
        if(color[x] == -1){
            if(!dfs(x,st,cor ^ 1)) return false;
        }
        else{
            if(color[st] == color[x]) return false;
        }
    }
    return true;
}

bool judge(int gn,int bn,int n){
    memset(color,-1,sizeof(color));
    memset(gb,-1,sizeof(gb));
    int cnt = 0;
    for(int i = 1 ; i <= n;i++){
        if(color[i] == -1){
            if(!dfs(i,0,cnt)) return false;
            else cnt += 2;
        }
    }
    for(int i = 0 ; i < gn;i++){
        int be = color[g[i]];
        if(gb[be] == -1 && gb[be^1] == -1){
            gb[be] = 0,gb[be ^ 1] = 1;
        }
        else if(gb[be] != 0) return false;
    }
    for(int i = 0 ; i < bn;i++){
        int be = color[b[i]];
        if(gb[be] == -1 && gb[be^1] == -1){
            gb[be] = 1,gb[be ^ 1] = 0;
        }
        else if(gb[be] != 1) return false;
    }
    int all = 0;
    for(int i = 0; i < cnt;i++) 
        if(gb[i] == -1) 
            all++;
    return all <= 2;
}

int main(){
    int n,m,gn,bn;
    while(~scanf("%d %d %d %d",&n,&m,&gn,&bn)){
        for(int i =  1 ; i <= n;i++) edge[i].clear();
        int l,r;
        while(m--){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            edge[r].push_back(l);
        }
        for(int i = 0 ; i < gn;i++) scanf("%d",&g[i]);
        for(int i = 0 ; i < bn;i++) scanf("%d",&b[i]);
        puts(judge(gn,bn,n)?"YES":"NO");
    }
    return 0;
}
