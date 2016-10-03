#include<bits/stdc++.h>
using namespace std;
#define LL long long 
const int maxn = 112345;

LL arr[maxn],anw[maxn];
int ran[maxn];
bool vis[maxn];

int fa[maxn];
int fnd(int x){
    return fa[x] == x ? fa[x] : fa[x] = fnd(fa[x]);
}
void join(int x,int y){
    x = fnd(x),y = fnd(y);
    if(x != y){
        fa[x] = y;
        arr[y] += arr[x];
    }
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) cin>>ran[i];
    for(int i=1;i<=n;i++) fa[i] = i;
    memset(vis,0,sizeof(vis));
    LL ans = 0;
    for(int i=n;i>=1;i--){
        anw[i] = ans;
        int x = ran[i];
        vis[x] = true;
        if(vis[x-1]) join(x-1,x);
        if(vis[x+1]) join(x+1,x);
        ans = max(ans,arr[fnd(x)]);
    }
    for(int i=1;i<=n;i++)
        cout<<anw[i]<<endl;
    return 0;
}
