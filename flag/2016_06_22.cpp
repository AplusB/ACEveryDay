#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
char mp[maxn][maxn];
int dis[maxn][maxn][4], vis[maxn][maxn][4], n, m;
int dir[4][2] = {
    0, -1, -1, 0, 0, 1, 1, 0
};
int pd[4] = { 2, 3, 0, 1 };
const char s[] = "+-|^><vLRUD*";
int st[300];
int wait[16][16][4];
int rota[16][4];
int sx, sy, ex, ey;

void init(){
    st['+'] = 15; st['-'] = 5; st['|'] = 10; st['^'] = 2; st['v'] = 8; st['<'] = 1; st['>'] = 4;
    st['L'] = 14; st['R'] = 11; st['U'] = 13; st['D'] = 7; st['*'] = 0;
    for(int t1 = 0; t1 < 12; t1++){
        int s1 = st[s[t1]];
        for(int t2 = 0; t2 < 12; t2++){
            int s2 = st[s[t2]];
            for(int k = 0; k < 4; k++){
                wait[s1][s2][k] = INF;
                for(int i = 0; i < 4; i++) if(s1 & (1 << i)){
                    for(int j = 0; j < 4; j++) if(s2 & (1 << j)){
                        if((k - i + 4) % 4 == (pd[k] - j + 4) % 4){
                            wait[s1][s2][k] = min(wait[s1][s2][k], (k - i + 4) % 4);
                        }
                    }
                }
            }
        }
    }
    for(int i = 0; i < 12; i++){
        int state = st[s[i]];
        for(int j = 0; j < 4; j++){
            rota[state][j] = ((state << j) | (state >> (4 - j))) & 15;
        }
    }
}

bool InMap(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

struct Node{
    int dis, x, y, sp;
    Node(){}
    Node(int _dis, int _x, int _y, int _sp): dis(_dis), x(_x), y(_y), sp(_sp) {}
    bool operator<(const Node& tmp) const{
        return dis > tmp.dis;
    }
};

int bfs(){
    priority_queue < Node > que;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[sx][sy][0] = 0;
    que.push(Node(0, sx, sy, 0));
    while(!que.empty()){
        int px = que.top().x;
        int py = que.top().y;
        int sp = que.top().sp;
        que.pop();
        if(px == ex && py == ey) return dis[px][py][sp];
        if(vis[px][py][sp]) continue;
        vis[px][py][sp] = 1;
        for(int i = 0; i < 4; i++){
            int x = px + dir[i][0];
            int y = py + dir[i][1];
            if(!InMap(x, y)) continue;
            int now = st[mp[px][py]];
            int nxt = st[mp[x][y]];
            now = rota[now][sp];
            nxt = rota[nxt][sp];
            if(wait[now][nxt][i] == INF) continue;
            int nsp = (sp + wait[now][nxt][i]) % 4;
            if(!vis[x][y][nsp] && dis[x][y][nsp] > dis[px][py][sp] + wait[now][nxt][i] + 1){
                dis[x][y][nsp] = dis[px][py][sp]+ wait[now][nxt][i] + 1;
                que.push(Node(dis[x][y][nsp], x, y, nsp));
            }
        }
    }
    return -1;
}

int main(){
    init();
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%s", mp[i] + 1);
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
    printf("%d\n", bfs());
    return 0;
}


