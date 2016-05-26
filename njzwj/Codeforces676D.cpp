#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template <class T> T sq(T x) { return x*x; }
template <class T> T tabs(T x) { return x<0?-x:x; }

#define ff first
#define ss second

const int maxn=1005;
const double eps=1e-8;
char mp[maxn][maxn];
bool vis[maxn][maxn][4];
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
int xt, yt, xm, ym, n, m;
struct P {
    int x, y, r, stp;
    P() {}
    P(int x, int y, int r, int stp):x(x), y(y), r(r), stp(stp) {}
    bool operator<(const P&rhs) const {
        return stp>rhs.stp;
    }
};
priority_queue<P> que;

inline bool check(char c, int d) {
    if (d==0) {
        return c=='+'||c=='|'||c=='^'||c=='L'||c=='R'||c=='D';
    }else if (d==1) {
        return c=='+'||c=='-'||c=='>'||c=='L'||c=='U'||c=='D';
    }else if (d==2) {
        return c=='+'||c=='|'||c=='v'||c=='L'||c=='R'||c=='U';
    }else {
        return c=='+'||c=='-'||c=='<'||c=='U'||c=='R'||c=='D';
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i=0;i<n;++i) scanf("%s", mp[i]);
    scanf("%d%d%d%d", &yt, &xt, &ym, &xm);
    --xt, --yt, --xm, --ym;

    memset(vis, false, sizeof(vis));
    P cur=P(xt, yt, 0, 0);
    vis[yt][xt][0]=true;
    que.push(cur);
    while (!que.empty()) {
        cur=que.top();
        que.pop();
        if (cur.x==xm&&cur.y==ym) {
            printf("%d\n", cur.stp);
            return 0;
        }
        for (int k=0;k<4;++k) {
            int nx=cur.x+dx[k], ny=cur.y+dy[k];
            if (nx<0||ny<0||nx>=m||ny>=n) continue;
            if (vis[ny][nx][cur.r]) continue;
            if (check(mp[cur.y][cur.x], (4+k-cur.r)%4)&&check(mp[ny][nx], (6+k-cur.r)%4)) {
                que.push(P(nx, ny, cur.r, cur.stp+1));
                vis[ny][nx][cur.r]=true;
            }
        }
        if (!vis[cur.y][cur.x][(1+cur.r)%4]) {
            que.push(P(cur.x, cur.y, (1+cur.r)%4, cur.stp+1));
        }
    }
    printf("-1\n");
    return 0;
}