#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 212345;
const int INF = 1e9+10;

int ma[maxn],mi[maxn];
int n;

#define root 1,1,n
#define Now int o,int l,int r
#define lson o<<1,l,m
#define rson o<<1|1,m+1,r
#define Mid int m = (l+r)>>1;

struct segtree{
    int arr[maxn*4];
    function<int(int,int) > fun;
    void build(Now,int *s){
        if(l==r){
            arr[o] = s[l];
            return;
        }
        Mid;
        build(lson,s),build(rson,s);
        arr[o] = fun(arr[o<<1],arr[o<<1|1]);
    }
    void init(function<int(int,int)> f,int *s){
        fun = f;
        build(root,s);
    }
    int query(Now,int ql,int qr){
        if(ql <= l && r <= qr){
            return arr[o];
        }
        int ret = -fun(INF,-INF);
        Mid;
        if(ql <= m) ret = fun(ret,query(lson,ql,qr));
        if(m+1 <= qr) ret = fun(ret,query(rson,ql,qr));
        return ret;
    }
    int query(int l,int r){
        return query(root,l,r);
    }
};

segtree Ma,Mi;

void init(){
    Ma.init([](int x,int y){return max(x,y);},ma);
    Mi.init([](int x,int y){return min(x,y);},mi);
}

int maxer(int l,int r){
    return Ma.query(l,r);
}
int miner(int l,int r){
    return Mi.query(l,r);
}

int bnd(int x,function<bool(int,int)> cmp){
    int st=1,ed=n;
    int best=n+1;
    while(st < ed){
        int mid = (st + ed)/2;
        if(cmp(maxer(x,mid),miner(x,mid)))
            best=mid,ed=mid-1;
        else
            st = mid+1;
    }
    return best;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&ma[i]);
    for(int i=1;i<=n;i++) scanf("%d",&mi[i]);
    auto l = [](int x,int y){return x > y;};
    auto r = [](int x,int y){return x >= y;};
    init();
    LL ans = 0;
    for(int i=1;i<=n;i++){
        ans += bnd(i,l)-bnd(i,r);
    }
    printf("%I64d\n",ans);
}
