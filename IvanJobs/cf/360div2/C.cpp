#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>

using namespace std;


#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

set<int> adj[100000+100];
int colors[100000+100];

int main() {
    REP(i, 100100) colors[i] = -1;
    int n, m;
    scanf("%d%d", &n, &m);
    REP(t, m) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        adj[v1].insert(v2);
        adj[v2].insert(v1);
        colors[v1] = 2;
        colors[v2] = 2;
    }

    bool ok = true;

    FOR(v, 1, n) {
        if (colors[v] == 2) {
            queue<pair<int, int> > q;
            q.push(make_pair(v, 0));

            while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                colors[curr.first] = curr.second;
                set<int>& s = adj[curr.first];
                for (auto item : s) {
                    if (colors[item] == 2) {
                        q.push(make_pair(item, 1 - curr.second));
                    } else if (colors[item] == 1 - curr.second) {
                        // fine, do nothing
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok == false) break;
            }
            if (ok == false) break;
        }
    }

    if (ok == false) {
        printf("-1\n");
    } else {
        // collect
        vector<int> v1, v2;
        FOR(i, 1, n) {
            if (colors[i] == 0) v1.push_back(i);
            if (colors[i] == 1) v2.push_back(i);
        }
        printf("%d\n", v1.size());
        printf("%d", v1[0]);
        FOR(i, 1, v1.size() - 1) {
            printf(" %d", v1[i]);
        }
        printf("\n");

        printf("%d\n", v2.size());
        printf("%d", v2[0]);
        FOR(i, 1, v2.size() - 1) {
            printf(" %d", v2[i]);
        }
        printf("\n");


    }

    return 0;
}
