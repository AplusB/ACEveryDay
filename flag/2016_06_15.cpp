#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > G[maxn];
struct Node{
    int val, id;
    bool operator<(const Node& tmp) const{
        return val < tmp.val;
    }
}a[maxn];
int val[maxn], sum[maxn];

int main(){
    int n, u, v;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &val[i]);
            a[i].val = val[i];
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        for(int i = 1; i < maxn; i++) G[i].clear();
        for(int i = 1; i < n; i++){
            scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(u = 1; u <= n; u++){
            sum[u] = 0;
            for(int i = 0; i < G[u].size(); i++){
                v = G[u][i];
                sum[u] += val[v];
            }
        }
        int dam = 0;
        for(int i = n; i >= 1; i--){
            u = a[i].id;
            dam += sum[u];
            for(int j = 0; j < G[u].size(); j++){
                v = G[u][j];
                sum[v] -= val[u];
            }
        }
        printf("%d\n", dam);
    }
    return 0;
}
