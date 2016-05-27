#include <bits/stdc++.h>
typedef long long LL;
const int maxn = 50005;
const int Node = maxn * 20;
int ls[Node], rs[Node], sum[Node], root[maxn], tol;
int a[maxn], Left[maxn], Right[maxn];

int build(int l, int r){
    int rt = ++tol;
    sum[rt] = 0;
    if(l == r) return rt;
    int mid = (l + r) >> 1;
    ls[rt] = build(l, mid);
    rs[rt] = build(mid + 1, r);
    return rt;
}

int update(int rt, int p, int l, int r){
    int nrt = ++tol;
    ls[nrt] = ls[rt];
    rs[nrt] = rs[rt];
    sum[nrt] = sum[rt] + 1;
    if(l == r) return nrt;
    int mid = (l + r) >> 1;
    if(p <= mid)
        ls[nrt] = update(ls[rt], p, l, mid);
    else
        rs[nrt] = update(rs[rt], p, mid + 1, r);
    return nrt;
}

int query(int rt1, int rt2, int L, int R, int l, int r){
    if(L <= l && r <= R){
        return sum[rt2] - sum[rt1];
    }
    int mid = (l + r) >> 1;
    int s = 0;
    if(L <= mid)
        s += query(ls[rt1], ls[rt2], L, R, l, mid);
    if(mid < R)
        s += query(rs[rt1], rs[rt2], L, R, mid + 1, r);
    return s;
}

int S[maxn], top;
void gao(int n){
    top = 0;
    a[n + 1] = -1;
    for(int i = 1; i <= n + 1; i++){
        while(top && a[i] < a[S[top]]){
            Right[S[top]] = i - 1;
            top--;
        }
        S[++top] = i;
    }
    a[0] = INT_MAX;
    for(int i = n; i >= 0; i--){
        while(top && a[i] > a[S[top]]){
            Left[S[top]] = i + 1;
            top--;
        }
        S[++top] = i;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    gao(n);
    tol = 0;
    root[0] = build(1, n);
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        root[i] = update(root[i - 1], Right[i], 1, n);
        ans += query(root[Left[i] - 1], root[i], i, n, 1, n);
    }
    printf("%lld\n", ans);
    return 0;
}
