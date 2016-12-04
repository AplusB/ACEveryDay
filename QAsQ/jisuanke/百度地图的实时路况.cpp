#include<bits/stdc++.h>
using namespace std;

const int maxn = 312;
const int INF = 0x3f3f3f3f;
#define LL long long 

int mp[maxn][maxn][maxn];
int n;
LL ans;

void dfs(int deep,int l,int r){
    if(l == r){
        for(int i = 1 ; i <= n ; i ++){
            if(i == l) continue;
            for(int j = 1; j <= n ; j ++){
                if(j == i || j == l ) continue;
                ans += mp[deep-1][i][j] == INF ? -1 : mp[deep-1][i][j];
            }
        }
        return;
    }
    int mid = (l + r) / 2;

    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1; j <= n ; j ++)
            mp[deep][i][j] = mp[deep-1][i][j];
    for(int k = mid + 1 ; k <= r; k ++){
        for(int i = 1; i <= n ; i ++){
            for(int j = 1 ; j <= n ;j  ++){
                mp[deep][i][j] = min(mp[deep][i][j],mp[deep][i][k] + mp[deep][k][j]);
            }
        }
    }
    dfs(deep+1,l,mid);

    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1; j <= n ; j ++)
            mp[deep][i][j] = mp[deep-1][i][j];
    for(int k = l ; k <= mid; k ++){
        for(int i = 1; i <= n ; i ++){
            for(int j = 1 ; j <= n ;j  ++){
                mp[deep][i][j] = min(mp[deep][i][j],mp[deep][i][k] + mp[deep][k][j]);
            }
        }
    }
    dfs(deep+1,mid+1,r);
}

int main(){
    scanf("%d",&n);

    for(int i = 1; i <= n ; i ++){
        for(int j = 1; j <= n ; j ++){
            scanf("%d",&mp[0][i][j]);
            if(mp[0][i][j] == -1) mp[0][i][j] = INF;
        }
    }
    ans = 0;
    dfs(1,1,n);
    printf("%lld\n",ans);
    return 0;
}

