#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<string, int> mp;
vector<int> edge[100010];
int vis[22222];

bool dfs(int u)
{
    vis[u] = 1;
    for(int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if(!vis[v]) {
            if(!dfs(v))
                return false;
        } else if(vis[v] == 1) {
            return false;
        }
    }
    vis[u] = 2;
    return true;
}
int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        mp.clear();
        int n;
        scanf("%d", &n);
        char a[11], b[11];
        int tot = 0;
        for(int i = 0; i < 20010; i++) edge[i].clear();
        for(int i = 0; i < n; i++) {
            scanf("%s%s", a, b);
            if(mp.find(a) == mp.end()) {
                mp[a] = tot++;
            }
            if(mp.find(b) == mp.end()) {
                mp[b] = tot++;
            }
            edge[mp[a]].push_back(mp[b]);
        }
        memset(vis, 0, sizeof(vis));
        bool flag = true;
        for(int i = 0; i < tot; i++) if(!vis[i]){
            if(!dfs(i)) {
                flag = false;
                break;
            }
        }
        printf("Case %d: ",ca ++);
        if(flag) puts("Yes");
        else puts("No");
    }
    return 0;
}
