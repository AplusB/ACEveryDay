#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define mkp make_pair
#define pub push_back
#define B(x) (1<<(x))
#define lson rt << 1
#define rson rt << 1 | 1
typedef long long LL;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;
//*****************************我好弱啊，被一帆带飞了！**********************************//
//***************************************************************************************//
//***************************************************************************************//
//***************************************************************************************//
//********************************百度之星求拿衣服***************************************//
//***************************************************************************************//
//***************************************************************************************//
//***************************************************************************************//
//***************************你个傻逼记得改maxn的大小啊**********************************//
const int maxn = 1e5 + 5;
int sum[maxn];

struct Seg{
    int l, r;
    Seg(){}
    Seg(int _l, int _r): l(_l), r(_r) {}
};
vector < Seg > L, R;
vector < int > p;
struct Gao{
    int p, cnt, f;
    Gao();
    Gao(int _p, int _cnt, int _f): p(_p), cnt(_cnt), f(_f) {}
    bool operator<(const Gao& tmp) const{
        return p < tmp.p;
    }
};
vector < Gao > G;

int main () {
    int T, n, l, r, z, d, cnt;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        L.clear();
        R.clear();
        p.clear();
        G.clear();
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d", &l, &r, &z, &d);
            if(l + z < r - z) continue;
            if(d < 0){
                L.pub(Seg(r - z, l + z));
            }else{
                R.pub(Seg(r - z, l + z));
            }
            p.pub(r - z);
            p.pub(l + z);
        }
        sort(p.begin(), p.end());
        p.erase(unique(p.begin(), p.end()), p.end());
        //L:
        if(p.size()){
            fill(sum, sum + p.size() + 1, 0);
            for(int i = 0; i < L.size(); i++){
                L[i].l = lower_bound(p.begin(), p.end(), L[i].l) - p.begin() + 1;
                L[i].r = lower_bound(p.begin(), p.end(), L[i].r) - p.begin() + 1;
                sum[L[i].l]++;
                sum[L[i].r + 1]--;
            }
            for(int i = 1; i <= p.size(); i++){
                sum[i] += sum[i - 1];
            }
            for(int i = 0; i < L.size(); i++){
                G.pub(Gao(L[i].l, sum[L[i].l], 0));
                G.pub(Gao(L[i].r, sum[L[i].r, 1], 0));
            }
            //R:
            fill(sum, sum + p.size() + 1, 0);
            for(int i = 0; i < R.size(); i++){
                R[i].l = lower_bound(p.begin(), p.end(), R[i].l) - p.begin() + 1;
                R[i].r = lower_bound(p.begin(), p.end(), R[i].r) - p.begin() + 1;
                sum[R[i].l]++;
                sum[R[i].r + 1]--;
            }
            for(int i = 1; i <= p.size(); i++){
                sum[i] += sum[i - 1];
            }
            for(int i = 0; i < R.size(); i++){
                G.pub(Gao(R[i].r, sum[R[i].r], 1));
                G.pub(Gao(R[i].l, sum[R[i].l], 1));
            }
        }
        //count:
        sort(G.begin(), G.end());
        int mx = 0;
        int ans = 0;
        for(int i = 0; i < G.size(); i++){
            if(G[i].f)
                mx = max(mx, G[i].cnt);
            else
                ans = max(ans, mx + G[i].cnt);
        }
        ans = max(ans, mx);
        printf("Case #%d:\n%d\n", cas, ans);
    }
    return 0;
}
