出门比赛，忘记了，补一下
#include <bits/stdc++.h>
using namespace std;
#define B(x) (1<<(x))
const int maxn = 50005;
const int Node = maxn * 60;
int nxt[Node][2];
int num[Node];
int root[maxn];
int tol;

void init(){
    root[0] = tol = 0;
    num[tol] = 0;
    memset(nxt[tol], 0, sizeof nxt[tol]);
}

int newNode(int x){
    num[++tol] = num[x] + 1;
    memcpy(nxt[tol], nxt[x], sizeof nxt[x]);
    return tol;
}

int ins(int rt, int x){
    int p, nrt;
    p = nrt = newNode(rt);
    for(int i = 30, c; i >= 0; i--){
        c = x >> i & 1;
        nxt[p][c] = newNode(nxt[p][c]);
        p = nxt[p][c];
    }
    return nrt;
}

int fnd(int p1, int p2, int x){
    int ans = 0;
    for(int i = 30, c; i >= 0; i--){
        c = x >> i & 1;
        if(num[nxt[p2][!c]] - num[nxt[p1][!c]]){
            p1 = nxt[p1][!c];
            p2 = nxt[p2][!c];
            ans |= B(i);
        }else{
            p1 = nxt[p1][c];
            p2 = nxt[p2][c];
        }
    }
    return ans;
}

int main(){
    int N, Q, x, l, r;
    scanf("%d%d", &N, &Q);
    init();
    for(int i = 1; i <= N; i++){
        scanf("%d", &x);
        root[i] = ins(root[i - 1], x);
    }
    while(Q--){
        scanf("%d%d%d", &x, &l, &r); l++; r++;
        printf("%d\n", fnd(root[l - 1], root[r], x));
    }
	return 0;
}
