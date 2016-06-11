#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
int a[maxn][maxn], sz[maxn];
int s[maxn], e[maxn];
int t1[maxn], t2[maxn];

struct Node{
    int s, e, sz;
    bool operator <(const Node& tmp) const{
        if(s != tmp.s)
             return s < tmp.s;
        return e < tmp.e;
    }
}ary[maxn];

int main(){
    int n, q, xi, ai, yi, bi;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &sz[i]);
        s[i] = 0;
        for(int j = 1; j <= sz[i]; j++){
            scanf("%d", &a[i][j]);
            s[i] = max(s[i], max(a[i][j] - j + 1, 0));
        }
        e[i] = s[i] + sz[i];
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d%d", &xi, &ai, &yi, &bi);
        int sz1 = 0, sz2 = 0;
        for(int i = 1; i <= ai; i++){
            t1[++sz1] = a[xi][i];
        }
        for(int i = bi + 1; i <= sz[yi]; i++){
            t1[++sz1] = a[yi][i];
        }
        for(int i = 1; i <= bi; i++){
            t2[++sz2] = a[yi][i];
        }
        for(int i = ai + 1; i <= sz[xi]; i++){
            t2[++sz2] = a[xi][i];
        }
        sz[xi] = sz2;
        sz[yi] = sz1;
        s[xi] = 0;
        for(int i = 1; i <= sz2; i++){
            a[xi][i] = t2[i];
            s[xi] = max(s[xi], max(a[xi][i] - i + 1, 0));
        }
        e[xi] = s[xi] + sz2;
        s[yi] = 0;
        for(int i = 1; i <= sz1; i++){
            a[yi][i] = t1[i];
            s[yi] = max(s[yi], max(a[yi][i] - i + 1, 0));
        }
        e[yi] = s[yi] + sz1;
        for(int i = 1; i <= n; i++){
            ary[i].s = s[i];
            ary[i].e = e[i];
            ary[i].sz = sz[i];
        }
        sort(ary + 1, ary + 1 + n);
        int ans = ary[1].s, now = ary[1].s;
        for(int i = 1; i <= n; i++){
            if(now >= ary[i].s){
                now += ary[i].sz;
            }else{
                ans += ary[i].s - now;
                now = ary[i].e;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
