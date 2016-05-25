#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second
const int maxn=20005;
pii pts[maxn];
ll cnt[maxn], pos[maxn];

void add(int k, int num, ll *st) {
    while (k<maxn) {
        st[k]+=num;
        k+=k&-k;
    }
}
ll query(int k, ll *st) {
    ll ans=0;
    while (k) {
        ans+=st[k];
        k-=k&-k;
    }
    return ans;
}

int main() {
    int n;
    ll ans=0;
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d%d", &pts[i].ff, &pts[i].ss);
    sort(pts, pts+n);
    memset(cnt, 0, sizeof(cnt));
    memset(pos, 0, sizeof(pos));
    for (int i=0;i<n;++i) {
        int v=pts[i].ff, x=pts[i].ss;
        ll cntpre=query(x, cnt), cntnxt=query(maxn-1, cnt)-cntpre;
        ll pospre=query(x, pos), posnxt=query(maxn-1, pos)-pospre;
        ans+=(cntpre*x-pospre+posnxt-cntnxt*x)*v;
        add(x, 1, cnt);
        add(x, x, pos);
    }
    printf("%lld\n", ans);
    return 0;
}
