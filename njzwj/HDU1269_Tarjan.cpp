// Tarjan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=10005;
const int maxm=100005;
struct EG {
    int x, y, z;
    EG() {}
    EG(int x, int y, int z):x(x), y(y), z(z) {}
}edge[maxm];
int head[maxn], cnt, n, m;
int dfn[maxn], low[maxn], index;
bool inStk[maxn];

void addedge(int u, int v, int w) {
    edge[cnt]=EG(v, w, head[u]);
    head[u]=cnt++;
}

void Tarjan(int u) {
    int tmp=index++;
    dfn[u]=low[u]=tmp;
    inStk[u]=true;
    for (int p=head[u];p>=0;p=edge[p].z) {
        int v=edge[p].x;
        if (dfn[v]<0) {
            Tarjan(v);
            low[u]=min(low[u], low[v]);
        }else if (inStk[v]) {
            low[u]=min(low[u], low[v]);
        }
    }
}

int main() {
    while (scanf("%d%d", &n, &m)&&n) {
        bool flag=true;
        memset(head, 0xff, sizeof(head));
        cnt=0;
        for (int i=0;i<m;++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            addedge(x, y, 1);
        }
        // Tarjan
        memset(inStk, false, sizeof(inStk));
        memset(dfn, 0xff, sizeof(dfn));
        index=0;
        for (int i=0;i<n;++i) {
            if (dfn[i]>=0) continue;
            Tarjan(i);
        }
        for (int i=0;i<n;++i)
            if (low[i]) {
                flag=false;
                break;
            }

        printf("%s\n", flag?"Yes":"No");
    }
    return 0;
}
