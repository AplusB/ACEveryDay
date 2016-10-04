#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7, maxn = 55;
#define LL long long 
bool edge[maxn][maxn];

LL ans;
int poi[maxn];

bool check(int num){
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            for(int k=j+1;k<num;k++){
                if(edge[poi[i]][poi[j]] 
                && edge[poi[j]][poi[k]] 
                && edge[poi[k]][poi[i]]) return false;
                if(!edge[poi[i]][poi[j]] 
                && !edge[poi[j]][poi[k]] 
                && !edge[poi[k]][poi[i]]) return false;
            }
        }
    }
    return true;
}

void dfs(int st,int use,int n){
    if(st > n) return;
    dfs(st+1,use,n);
    poi[use++] = st;
    if(use >= 3){
        if(check(use) == false) return;
        else{
            ans--;
        }
    }
    dfs(st+1,use,n);
}


int main(){
    int T,icase = 1;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        memset(edge,0,sizeof(edge));
        int x,y;
        while(m--){
            scanf("%d %d",&x,&y);
            edge[x][y] = edge[y][x] = true;
        }
        ans = 1;
        for(int i=0;i<n;i++) (ans *= 2 ) %= mod;
        ans -= n + n * (n-1) / 2 + 1;
        dfs(1,0,n);
        ans = ((ans % mod ) + mod ) % mod;
        printf("Case #%d: %I64d\n",icase++,ans);
    }
    return 0;
}
