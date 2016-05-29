#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxm=50005;
const int maxn=10005;
struct EG {
    int x, y, z;
    EG() {}
    EG(int x, int y, int z):x(x), y(y), z(z) {}
}edge[maxm];
int head[maxn], cnt, dfn[maxn], low[maxn], out[maxn], stk[maxn], top, s[maxn];
bool inStk[maxn];
int index, sccnum;
int n, m;

void addedge(int u, int v, int w) {
    edge[cnt]=EG(v, w, head[u]);
    head[u]=cnt++;
}

void Tarjan(int u) {
    inStk[u]=true;
    dfn[u]=low[u]=index++;
    stk[top++]=u;
    for (int p=head[u];p>=0;p=edge[p].z) {
        int v=edge[p].x;
        if (dfn[v]<0) {
            Tarjan(v);
            low[u]=min(low[u], low[v]);
        }else if (inStk[v]&&low[v]<low[u]) {
            low[u]=low[v];
        }
    }
    if (low[u]==dfn[u]) {
        sccnum++;
        int v;
        do {
            v=stk[--top];
            inStk[v]=false;
            s[v]=sccnum;
        }while (low[v]!=dfn[v]);
    }
}

int main() {
    while (scanf("%d%d", &n, &m)!=EOF) {
        memset(head, 0xff, sizeof(head));
        memset(dfn, 0xff, sizeof(dfn));
        memset(low, 0xff, sizeof(low));
        memset(inStk, false, sizeof(inStk));
        memset(s, 0, sizeof(s));
        cnt=0;
        index=0;
        sccnum=0;
        top=0;
        for (int i=0;i<m;++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            addedge(x, y, 1);
        }
        for (int i=1;i<=n;++i) {
            if (dfn[i]<0) {
                Tarjan(i);
            }
        }
        if (sccnum==1) {
            printf("%d\n", n);
            continue;
        }

        memset(out, 0, sizeof(out));
        for (int i=1;i<=n;++i) {
            for (int p=head[i];p>=0;p=edge[p].z) {
                if (s[i]!=s[edge[p].x]) out[s[i]]=1;
            }
        }
        int a=0, b=0;

        for (int i=1;i<=sccnum;++i) {
            if (out[i]) ++a;
            else b=i;
        }
        if (a==sccnum-1) {
            a=0;
            for (int i=1;i<=n;++i) {
                if (s[i]==b) ++a;
            }
            printf("%d\n", a);
        }else {
            printf("0\n");
        }
    }
    return 0;
}
