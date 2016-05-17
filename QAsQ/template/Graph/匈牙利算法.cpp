int mat[maxn];
bool vis[maxn];

bool dfs(int st){
    vis[st] = true;
    for(auto &x:edge[st]){
        if(!vis[x]){
            vis[x] = true;
            if(mat[x]==-1 || dfs(mat[x])){
                mat[x] = st,mat[st] = x;
                return true;
            }
        }
    }
    return false;
}

int cal(int n){
    memset(mat,-1,sizeof(mat));
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(mat[i] == -1){
            memset(vis,0,sizeof(vis));
            if(dfs(i))cnt++;
        }
    }
    return cnt;
}
