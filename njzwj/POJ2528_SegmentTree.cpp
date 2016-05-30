// Mayor's posters
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;
#define lch p<<1
#define rch p<<1|1
const int maxn=10005;
set<int> ans;
int num[maxn<<1], l[maxn], r[maxn], st[maxn<<3];
int mp[10000005];
int n, cnt;

void change(int p, int l, int r, int x, int y, int num) {
    if (x<=l&&r<=y) {
        st[p]=num;
        return;
    }
    int mid=(l+r)>>1;
    if (st[p]>=0) {
        st[lch]=st[rch]=st[p];
    }
    st[p]=-2;
    if (x<=mid) change(lch, l, mid, x, y, num);
    if (mid<y) change(rch, mid+1, r, x, y, num);
}

void query(int p, int l, int r) {
    if (st[p]>=0) {
        ans.insert(st[p]);
        return;
    }
    if (l==r||st[p]==-1) {
        return;
    }
    int mid=(l+r)>>1;
    query(lch, l, mid);
    query(rch, mid+1, r);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        cnt=0;
        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            scanf("%d%d", l+i, r+i);
            num[cnt++]=l[i];
            num[cnt++]=r[i];
        }
        sort(num, num+cnt);
        cnt=unique(num, num+cnt)-num;
        for (int i=0;i<cnt;++i) mp[num[i]]=i+1;
        memset(st, 0xff, sizeof(st));
        for (int i=0;i<n;++i) {
            change(1, 1, cnt, mp[l[i]], mp[r[i]], i);
        }
        ans.clear();
        query(1, 1, cnt);
        printf("%d\n", ans.size());
    }
    return 0;
}
