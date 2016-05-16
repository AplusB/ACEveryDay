#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


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

int calroot(int st,int fa,int all){
    int ret = -1;
    siz[st] = 1,msiz[st] = 0;
    for(vector<pair<int,int> >::iterator it =edge[st].begin();it!=edge[st].end();it++){
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

int lener[maxn],len;

void getlener(int st,int fa,int v){
    lener[len++] = v;
    for(vector<pair<int,int> >::iterator it = edge[st].begin();it!=edge[st].end();it++){
        int x = it->first;
        int val = it->second;
        if(vis[x]==false && x!=fa){
            getlener(x,st,v+val);
        }
    }
}
int k;
int getans(int st,int sv){
    len = 0;
    int ans = 0;
    getlener(st,0,sv);
    sort(lener,lener+len);
    lener[len] = 0;
    for(int i=0;i<len;i++){
        int v = k - lener[i];
        ans += upper_bound(lener,lener+len,v) - lower_bound(lener,lener+len,v);
    }
    return ans;
}

int dfs(int st){
    vis[st] = true;
    int ans = 0;
    len = 0;
    ans += getans(st,0);
    for(vector<pair<int,int> >::iterator it =edge[st].begin();it!=edge[st].end();it++){
        int x=  it->first;
        int v = it->second;
        if(vis[x]) continue;
        ans -= getans(x,v);
        ans += dfs(calroot(x,st,siz[x]));
    }
    return ans;
}
bool cal(int n){
    memset(vis,0,sizeof(vis));
    return dfs(calroot(1,0,n));
}

int main(){
    int n;
    while(~scanf("%d",&n) && n){
        init(n);
        int ed,v;
        for(int i=1;i<=n;i++){
            while(scanf("%d",&ed) && ed){
                scanf("%d",&v);
                Link(i,ed,v);
            }
        }
        while(~scanf("%d",&k) && k){
            puts(cal(n)?"AYE":"NAY");
        }
        puts(".");
    }
    return 0;
}
