#include <bits/stdc++.h>
using namespace std;

int n, m;
int match[2012];
bool used[2012];
int g[2012][2012];
bool dfs(int u)
{
    for(int i = 0; i < m; i++) {
        if(g[u][i] && !used[i]) {
            used[i] = true;
            if(match[i] == -1 || dfs(match[i])) {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int T, ca = 1;
    cin >> T;
    while(T--) {
        printf("Case #%d: ", ca++);
        map<string, int> m1, m2;
        string s1, s2;
        n = 0; m = 0;
        int tot;
        cin >> tot;
        memset(g, 0, sizeof(g));
        for(int i = 0; i < tot; i++) {
            cin >> s1 >> s2;
            if(m1.find(s1)==m1.end()) m1[s1] = n++;
            if(m2.find(s2)==m2.end()) m2[s2] = m++;
            g[m1[s1]][m2[s2]] = 1;
        }
        int ret = 0;
        memset(match, -1, sizeof(match));
        memset(used, false, sizeof(used));
        for(int i = 0; i < n; i++) {
            memset(used, false, sizeof(used));
            if(dfs(i)) ret++;
        }
        cout << tot - (n + m- ret) << endl;
    }
    return 0;
}
