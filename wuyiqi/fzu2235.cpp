#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
    void print() {
        printf("%d %d\n", x , y);
    }
    bool operator < (const Point &cmp) const {
        return x < cmp.x || (x == cmp.x && y < cmp.y);
    }
    bool operator == (const Point &cmp) const {
        return x == cmp.x && y == cmp.y;
    }
}s, t;

const int N = 100007;
const int M = 100010;
struct HashTable
{
    int head[N], nxt[M];
    Point pnt[M];
    int E;
    void init() {
        E = 0;
        memset(head, -1, sizeof(head));
    }
    void insert(Point p) {
        long long h = (1LL * p.x * 1000007 + p.y) % N;
        for(int i = head[h]; i != -1; i = nxt[i]) {
            if(pnt[i] == p) {
                return ;
            }
        }
        pnt[E] = p;
        nxt[E] = head[h];
        head[h] = E++;
    }
    int find(Point p) {
        long long h = (1LL * p.x * 1000007 + p.y) % N;
        for(int i = head[h]; i != -1; i = nxt[i]) {
            if(pnt[i] == p) {
                return i;
            }
        }
        return -1;
    }
}mp;

int dx [] = {0, 1, 0, -1, 1, -1, -1, 1};
int dy [] = {1, 0, -1, 0, 1, -1, 1, -1};
int vis[M];
Point Q[M];
void bfs()
{
    int head = 0, tail = 0;
    memset(vis, -1, sizeof(vis));
    Q[++tail] = s;
    vis[mp.find(s)]=0;
    while(head < tail) {
        Point f = Q[++head];
        int fid = mp.find(f);
        for(int i = 0; i < 8; i++) {
            Point to;
            to.x = f.x + dx[i];
            to.y = f.y + dy[i];
            int id = mp.find(to);
            if(id != -1 && vis[id] == -1 ) {
                Q[++tail] = to;
                vis[id] = vis[fid] + 1;
                if(to == t) {
                    printf("%d\n", vis[id]);
                    return ;
                }
            }
        }
    }
    printf("-1\n");
}
bool read (int &x) {
    int c = getchar (); int sign = 1;
    while (~c && c < '0' || c > '9') { if (c == '-') sign = -1; c = getchar (); }
    for (x = 0; ~c && '0' <= c && c <= '9'; c = getchar ()) x = x * 10 + c - '0';
    x *= sign;
    return ~c;
}
int main()
{
    while(scanf("%d%d", &s.x, &s.y) == 2) {
        mp.init();
        read(t.x); read(t.y);
        mp.insert(s);
        mp.insert(t);
        int n;
        scanf("%d", &n);
        int r, a, b;
        for(int i = 0; i < n; i++) {
            read(r); read(a); read(b);
            for(int j = a;  j <= b; j++) {
                Point tmp;
                tmp.x = r; tmp.y = j;
                mp.insert(tmp);
            }
        }
        bfs();
    }
    return 0;
}
