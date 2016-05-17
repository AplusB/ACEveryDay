#include <bits/stdc++.h>
using namespace std;
 
int T;
int n;
map<string, int> m;
vector<int> g[20010];
int in[20010];
int cnt = 0;
 
bool tuopu() {
    queue<int> q;
    int num = 0;
    for(int i=1; i<=cnt; i++) {
        if(in[i] == 0)
            q.push(i),num++;
    }
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        int size = g[now].size();
        for(int i=0; i<size; i++) {
            int to = g[now][i];
            in[to] --;
            if(in[to] == 0)
                q.push(to), num++;
        }
    }
    if(num != cnt)
        return false;
    return true;
}
 
int main() {
    cin>>T;
    string tmp1,tmp2;
    for(int icase=1; icase<=T; icase++) {
        m.clear();
        cnt = 0;
        memset(in, 0, sizeof(in));
        cin>>n;
        for(int i=1; i<=2*n; i++) g[i].clear();
        for(int i=1; i<=n; i++) {
            cin>>tmp1>>tmp2;
            if(m[tmp1] == 0) {
                m[tmp1] = ++cnt;
            }
            if(m[tmp2] == 0) {
                m[tmp2] = ++cnt;
            }
            g[m[tmp1]].push_back(m[tmp2]);
            in[m[tmp2]]++;
        }
        printf("Case %d: ", icase);
        if(tuopu())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}