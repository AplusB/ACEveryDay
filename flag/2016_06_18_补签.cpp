#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int UP = 1e3 + 5;
const int maxn = 1e5 + 5;

struct BIT{
    int sum[UP], n;

    void init(int n){
        memset(sum, 0, sizeof sum);
        this->n = n;
    }

    inline int lowbit(int x){ return x & (-x); }

    void update(int x, int val){
        for(int i = x; i <= n; i += lowbit(i)){
            sum[i] += val;
        }
    }

    int query(int l, int r){
        int res = 0;
        for(int i = r; i; i -= lowbit(i)){
            res += sum[i];
        }
        for(int i = l - 1; i; i -= lowbit(i)){
            res -= sum[i];
        }
        return res;
    }

}gao1, gao2, gao3;

struct Node{
    int a, b;
    void read(){ scanf("%d%d", &a, &b); }
    bool operator<(const Node& tmp) const{
        if(a != tmp.a)
            return a < tmp.a;
        return b > tmp.b;
    }
}p[maxn];

LL ans[5];

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        gao1.init(m);
        gao2.init(m);
        gao3.init(m);
        memset(ans, 0, sizeof ans);
        for(int i = 1; i <= n; i++){
            p[i].read();
            if(p[i].a < p[i].b){
                gao1.update(p[i].a, 1);
            }else{
                gao2.update(p[i].a, 1);
            }
        }
        sort(p + 1, p + 1 + n);
        for(int i = 1; i <= n; i++){
            if(p[i].a < p[i].b){
                ans[4] += gao1.query(p[i].b + 1, m);
                ans[3] += gao2.query(p[i].b + 1, m);
                ans[3] += gao1.query(p[i].a + 1, p[i].b);
                ans[3] += gao3.query(p[i].b + 1, m);
                gao3.update(p[i].b, 1);
            }else{
                ans[3] += gao1.query(p[i].b + 1, m);
                ans[1] += gao2.query(1, p[i].b);
            }
        }
        ans[2] = (LL)n * n - ans[1] - ans[3] - ans[4];
        cout << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << '\n';
    }
    return 0;
}


