#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 11234;

vector<pair<int,int> >edge[maxn];

void init(int n){
    for(int i=0;i<=n;i++){
        edge[i].clear();
    }
}

void Link(int st,int ed,int v){
    edge[st].push_back(make_pair(ed,v));
    edge[ed].push_back(make_pair(st,v));
}

bool vis[maxn];
int siz[maxn],msiz[maxn];

int lener[maxn],len;

int k;

int calroot(int st,int fa,int all){
    int ret = -1;
    siz[st] = 1,msiz[st] = 0;
    for(vector<pair<int,int> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = it->first;
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

int getpair(){
    int ret = 0;
    sort(lener,lener+len);
    int pos = len-1;
    for(int i=0;i<len;i++){
        while(pos>=0 && lener[pos]+lener[i]>k){
            pos--;
        }
        ret += max(pos-i,0);
    }
    return ret;
}

void getlener(int st,int fa,int v){
    lener[len++] = v;
    for(vector<pair<int,int> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = it->first,tv = it->second;
        if(x != fa && vis[x]==false){
            getlener(x,st,v+tv);
        }
    }
}

void outlener(){
    for(int i=0;i<len;i++){
        printf(i<len-1?"%d ":"%d|\n",lener[i]);
    }
}

int dfs(int st){
    vis[st] = true;
    int ans = 0;
    len = 0;
    getlener(st,-1,0);
    ans += getpair();
    for(vector<pair<int,int> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = it->first,v = it->second;
        if(vis[x]) continue;
        len = 0;
        getlener(x,st,v);
        ans -= getpair();
        ans += dfs(calroot(x,st,siz[x]));
    }
    return ans;
}

int cal(int n){
    memset(vis,0,sizeof(vis));
    return dfs(calroot(1,0,n));
}

int main(){
    int n;
    while(~scanf("%d %d",&n,&k) && (n||k)){
        int x,y,v;
        init(n);
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&x,&y,&v);
            Link(x,y,v);
        }
        printf("%d\n",cal(n));
    }
    return 0;
}
