#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;
#define LL long long 
vector<int> edge[maxn];
bool Map[maxn][maxn];

LL ans = 0;
int s;

int use[maxn];

void dfs(int st,int n,int us){
    if(us == s){
        //for(int i = 0;i<s;i++){ printf("%d_",use[i]); } puts("");
        ans++;
        return;
    }
    if(st > n) return;
    for(auto x : edge[st]){
        bool cst = true;
        for(int i = 0;i<us;i++){
            if(Map[use[i]][x] == false){
                cst = false;
                break;
            }
        }
        if(!cst) continue;
        use[us] = x;
        dfs(x,n,us+1);
    }
}

int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d %d",&n,&m,&s)){
        for(int i = 0;i<=n;i++) edge[i].clear();
        memset(Map,0,sizeof(Map));
        int l,r;
        while(m--){
            scanf("%d %d",&l,&r);
            edge[l].push_back(r);
            Map[r][l] = Map[l][r] = true;
        }
        for(int i = 1 ;i<=n;i++){
            sort(edge[i].begin(),edge[i].end());
        }
        ans = 0;
        for(int i = 1;i<n;i++){
            use[0] = i;
            dfs(i,n,1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

