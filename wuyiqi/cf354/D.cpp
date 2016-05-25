#include <bits/stdc++.h>
using namespace std;

#define mytype pair<pair<int, int>, int>
#define mm make_pair
int n, m;
char mp[1010][1010];
int x_s, y_s, x_t, y_t;
int dp[4][1010][1010];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool Min(int &x, int y)
{
    if(x == -1 || x > y) {
        x = y;
        return true;
    }
    return false;
}
struct  node
{
    int v[4];
    void init() {
        memset(v, 0, sizeof(v));
    }
    void unit() {
        for(int i = 0; i < 4; i++) {
            v[i] = 1;
        }
    }
};
map<char, node> gao;
void init()
{
    node tmp;
    for(int i = 0; i < 4; i++) {
        tmp.v[i] = 1;
    }
    gao['+'] = tmp;

    tmp.init();
    tmp.v[0] = tmp.v[2] = 1;
    gao['-'] = tmp;

    tmp.init(); tmp.v[1] = tmp.v[3] = 1;
    gao['|'] = tmp;

    tmp.init(); tmp.v[3] = 1;
    gao['^'] = tmp;

    tmp.init(); tmp.v[0] = 1;
    gao['>'] = tmp;

    tmp.init(); tmp.v[2] = 1;
    gao['<'] = tmp;

    tmp.init(); tmp.v[1] = 1;
    gao['v'] = tmp;

    tmp.unit(); tmp.v[2] = 0;
    gao['L'] = tmp;

    tmp.unit(); tmp.v[0] = 0;
    gao['R'] = tmp;

    tmp.unit(); tmp.v[3] = 0;
    gao['U'] = tmp;

    tmp.unit(); tmp.v[1] = 0;
    gao['D'] = tmp;


    tmp.init();
    gao['*'] = tmp;
}
bool connect(char ch1, char ch2, int d1, int d2, int dir)
{
    node node1 = gao[ch1];
    node node2 = gao[ch2];

    for(int i = 0; i < dir; i++) {
        rotate(node1.v, node1.v + 3, node1.v + 4);
        rotate(node2.v, node2.v + 3, node2.v + 4);
    }
//    printf("%c %c %d %d %d\n", ch1, ch2, d1, d2, dir);
    return node1.v[d1] + node2.v[d2] == 2;
}
int main()
{
    init();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        scanf("%s", mp[i]);
    }
    cin >> x_s >> y_s ;
    cin >> x_t >> y_t ;
    x_s--; y_s--;
    x_t--; y_t--;
    memset(dp, -1, sizeof(dp));
    dp[0][x_s][y_s] = 0;
    queue<mytype> Q;
    Q.push(mm(mm(x_s, y_s), 0));
    while(!Q.empty()) {
        mytype fr = Q.front();
        int x = fr.first.first;
        int y = fr.first.second;
        int dir = fr.second;
        if(x == x_t && y == y_t) {
            cout << dp[dir][x][y] << endl;
            return 0;
        }
        Q.pop();

        if( Min(dp[(dir + 1) % 4][x][y], dp[dir][x][y] + 1) ) {
            Q.push(mm(mm(x, y), (dir + 1) % 4));
        }

        for(int i = 0; i < 4; i++) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
                if(dp[dir][tx][ty] == -1 && connect(mp[x][y], mp[tx][ty],i,(i+2)%4, dir)) {
 //                   printf("dp[%d][%d][%d]=%d tx=%d ty=%d\n", dir, x, y, dp[dir][x][y], tx, ty);
                    dp[dir][tx][ty] = dp[dir][x][y] + 1;
                    Q.push(mm(mm(tx, ty), dir));
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
