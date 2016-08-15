#include<bits/stdc++.h>
using namespace std;
const int maxn = 112345;
int fa[maxn], ds[maxn], rk[maxn];
stack<int> S;
void init(int n) {
    for (int i = 1; i <= n; ++ i) {
        fa[i] = i, rk[i] = ds[i] = 0;
    }
    while(S.empty()==false) S.pop();
}
int dis(int x) {
    int r(0);
    for (; x != fa[x]; x = fa[x])
        r ^= ds[x];
    return r;
}
int fnd(int x) {
    while (x != fa[x]) x = fa[x];
    return fa[x];
}
void merge(int x, int y, int d) { //x -(d)-> y
    x = fnd(x); y = fnd(y);
    if (x == y) return; //ignore
    if (rk[x] > rk[y])
        swap(x, y);
    if (rk[x] == rk[y])
        ++ rk[y], S.push(-y);
    fa[x] = y; ds[x] = d;
    S.push(x);
}
void restore(int ed) { //back to state before ed'th operator
    while(S.size() > ed) {
        if (S.top() < 0)
            --rk[-S.top()];
        else
            fa[S.top()] = S.top(), ds[S.top()] = 0;
        S.pop();
    }
}
