#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define lson l, m, rt<<1
#define rson m + 1, r, rt<<1|1

using namespace std;
const int maxn = 20010;
struct Seg{
    int l, r, h, s;
    Seg(){}
    Seg(int a, int b, int c, int d):l(a), r(b), h(c), s(d){}
    bool operator < (const Seg &tmp)const
    {
        if(h == tmp.h) return s > tmp.s;
        return h < tmp.h;
    }
}ss[maxn << 2];
int segc[maxn<<2];
int lb[maxn<<2], rb[maxn<<2];
int sum[maxn<<2];
int cnt[maxn<<2];
void PushUp(int l, int r, int rt){
    if(cnt[rt])    {
        lb[rt] = rb[rt] = 1;
        sum[rt] = r - l + 1;
        segc[rt] = 2;
    }
    else if(l == r) lb[rt] = rb[rt] = segc[rt] = sum[rt] = 0;
    else {
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
        lb[rt] = lb[rt<<1];
        rb[rt] = rb[rt<<1|1];
        segc[rt] = segc[rt<<1] + segc[rt<<1|1];
        if(lb[rt<<1|1] && rb[rt<<1]) segc[rt] -= 2;
    }
}
void Update(int L, int R, int c, int l, int r, int rt){
    if(L <= l && r <= R)
    {
        cnt[rt] += c;
        PushUp(l, r, rt);
        return;
    }
    int m = (l + r) >> 1;
    if(L <= m) Update(L, R, c, lson);
    if(m < R) Update(L, R, c, rson);
    PushUp(l, r, rt);
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i, m = 0;
        int a, b , c, d;
        int ll = 10000, rr = -10000;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d%d",&a, &b, &c, &d);
            if(ll > a) ll = a;
            if(c > rr) rr = c;
            ss[m++] = Seg(a, c, b, 1);
            ss[m++] = Seg(a, c, d, -1);
        }
        sort(ss, ss+m);
        int ret = 0;
        int las = 0;
        memset(cnt, 0, sizeof(cnt));
        for(i = 0; i < m; i++)
        {
            Update(ss[i].l, ss[i].r - 1, ss[i].s, ll,  rr - 1, 1);
            if(las < sum[1])
                ret += sum[1] - las;
            else
                ret += las - sum[1];
            ret += (ss[i+1].h - ss[i].h) * segc[1];
            las = sum[1];
        }
        printf("%d\n", ret);
    }
}
