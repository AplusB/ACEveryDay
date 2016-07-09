#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 212345;
const int INF = 1e9+10;

int ma[maxn],mi[maxn];
int n;

struct segtree{
    int arr[maxn][20];
    function<int(int,int) > fun;
    void build(int *s){
        for(int i=1;i<=n;i++) arr[i][0] = s[i];
        for(int j=1;(1<<j) <= n;j++){
            for(int i=1;i + (1<<j)-1<=n;i++){
                arr[i][j] = fun(arr[i][j-1],arr[i+(1<<(j-1))][j-1]);
            }
        }
    }
    void init(function<int(int,int)> f,int *s){
        fun = f;
        build(s);
    }
    int query(int l,int r){
        int k = 0;
        while(1<<(k+1) <= r-l+1) k++;
        //printf("lr = %d %d v = %d\n",l,r,fun(arr[l][k],arr[r-(1<<k)+1][k]));
        return fun(arr[l][k],arr[r-(1<<k)+1][k]);
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

int lbnd(int x){
    int st=x,ed=n;
    int best=n+1;
    while(st <= ed){
        int mid = (st + ed)/2;
        if(maxer(x,mid) >= miner(x,mid))
            best=mid,ed = mid - 1;
        else
            st = mid + 1;
    }
    return best;
}
int rbnd(int x){
    int st=x,ed=n;
    int best=n+1;
    while(st <= ed){
        int mid = (st + ed)/2;
        if(maxer(x,mid) > miner(x,mid))
            best=mid,ed = mid - 1;
        else
            st = mid + 1;
    }
    return best;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&ma[i]);
    for(int i=1;i<=n;i++) scanf("%d",&mi[i]);
    init();
    LL ans = 0;
    for(int i=1;i<=n;i++){
        if(maxer(i,n) < miner(i,n)) continue;
        ans += rbnd(i)-lbnd(i);
    }
    printf("%I64d\n",ans);
}
