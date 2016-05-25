#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int fa[maxn];

void init(){
    for(int i = 0; i < maxn; i++){
        fa[i] = i;
    }
}

int fnd(int x){
    return fa[x] == x ? fa[x] : fa[x] = fnd(fa[x]);
}

void mrg(int x, int y){
    x = fnd(x);
    y = fnd(y);
    if(x != y) fa[x] = y;
}

int main(){
    int n, Q, l, r, ans = 0;
    char s[20];
    scanf("%d%d", &n, &Q);
    init();
    for(int i = 1; i <= Q; i++){
        scanf("%d%d%s", &l, &r, s);
        if(ans) continue;
        if(s[0] == 'e'){
            if(fnd(l - 1 + n) == fnd(r) && fnd(l - 1) == fnd(r + n))
                ans = i;
            else{
                mrg(l - 1, r);
                mrg(l - 1 + n, r + n);
            }
        }else{
            if(fnd(l - 1) == fnd(r) && fnd(l - 1 + n) == fnd(r + n))
                ans = i;
            else{
                mrg(l - 1 + n, r);
                mrg(l - 1, r + n);
            }
        }
    }
    if(!ans) ans = -1;
    printf("%d\n", ans);
    return 0;
}
