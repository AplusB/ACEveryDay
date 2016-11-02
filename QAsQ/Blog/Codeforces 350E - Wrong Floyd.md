# Codeforces 350E - Wrong Floyd

简单的构造，通过$A$数组的元素个数我们可以确定可以构造出来的图的边的上界。然后判断即可。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int maxn = 3123;

bool vis[maxn];

int getnod(int n){
    for(int i = 1;i<=n;i++) if(vis[i] == false) return i;
    return -1;
}
int getlef(int n){
    for(int i = 1;i<=n;i++) if(vis[i]) return i;
    return -1;
}
vector<pair<int,int> > ans;

bool check(int n,int m){
    int st;
    if((st = getnod(n)) == -1) return false;
    int lef = getlef(n);
    m--;
    ans.push_back(make_pair(lef,st));
    for(int i = 1;i<=n;i++){
        if(i == lef) continue;
        for(int j = i+1 ; j <= n;j++){
            if(j == lef) continue;
            if(m > 0){
                m--;
                ans.push_back(make_pair(i,j));
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if( i == lef || i == st) continue;
        if( m > 0 && !vis[i]){
            m--;
            ans.push_back(make_pair(i,lef));
        }
    }
    return m == 0;
}

int main(){
    int n,m,k;
    memset(vis,0,sizeof(vis));
    scanf("%d %d %d",&n,&m,&k);
    int x;
    while(k--){
        scanf("%d",&x);
        vis[x] = true;
    }
    if(!check(n,m)){
        puts("-1");
    }
    else{
        for(auto x : ans){
            printf("%d %d\n",x.first,x.second);
        }
    }
    return 0;
}
```

