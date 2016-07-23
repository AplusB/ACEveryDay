#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 212345;
LL k, ans;
vector<int> edge[maxn];

bool is[maxn];

LL dfs(int st,int fa){
    LL v = is[st];
    for(auto x : edge[st]){
        if(x == fa) continue;
        LL sv = dfs(x,st);
        ans += min(sv,k-sv);
        v += sv;
    }
    return v;
}

int main(){
    int n;
    scanf("%d %I64d",&n,&k);
    memset(is,0,sizeof(is));
    k *= 2;
    int x,y;
    for(int i=0;i<k;i++){
        scanf("%d",&x);
        is[x] = true;
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    ans = 0;
    dfs(1,0);
    printf("%I64d\n",ans);
    return 0;
}
