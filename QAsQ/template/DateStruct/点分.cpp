bool vis[maxn];
int siz[maxn],msiz[maxn];

int calroot(int st,int fa,int all){
    int ret = -1;
    siz[st] = 1,msiz[st] = 0;
    for(auto it : edge[st]){
        int x = it.first;
        if(x != fa && !vis[x]){
            int trot = calroot(x,st,all);
            if(ret==-1 || msiz[ret]>msiz[trot])
                ret = trot;
            siz[st] += siz[x];
            msiz[st] = max(msiz[st],siz[x]);
        }
    }
    msiz[st] = max(msiz[st],all - siz[st]);
    if(ret==-1 || msiz[ret]>msiz[st])
        ret = st;
    return ret;
}


int dfs(int st){
    vis[st] = true;
    int ans = 0;
    len = 0;

    \\update rooter

    for(auto it :edge[st]){
        int x = it.first,v = it.second;
        if(vis[x]) continue;

        \\update soner

        ans += dfs(calroot(x,st,siz[x]));
    }
    return ans;
}

int cal(int n){
    memset(vis,0,sizeof(vis));
    return dfs(calroot(1,0,n));
}


