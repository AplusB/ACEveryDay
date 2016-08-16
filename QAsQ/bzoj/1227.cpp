#include<bits/stdc++.h>
using namespace std;
const int mod= 2147483647;
const int maxn = 112345;
#define LL long long 
struct Msp{
    int msp[maxn],mlen;
    void init(){
        mlen = 0,msp[mlen++] = -1;
    }
    void done(){
        sort(msp,msp+mlen);
        mlen = unique(msp,msp+mlen) - msp;
    }
    void add(int x){
        msp[mlen++] = x;
    }
    int geter(int x){
        return lower_bound(msp,msp+mlen,x) - msp;
    }
    void upd(int &x){
        x = this->geter(x);
    }
}Mx,My;

LL comb[maxn][12];
void initC(){
    memset(comb,0,sizeof(comb));
    comb[0][0] = 1;
    for(int i=1;i<maxn;i++){
        comb[i][0] = comb[i-1][0];
        for(int j=1;j<=i && j < 12;j++){
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) & mod;
        }
    }
}

LL arr[maxn];
int lowbit(int x){return x & (-x);}
void upd(int x,LL k){
    while(x < maxn)
        (arr[x] += k ) &= mod,x += lowbit(x);
}
LL que(int x){
    LL ret = 0;
    while(x){
        (ret += arr[x]) &= mod , x -= lowbit(x);
    }
    return ret;
}

pair<int,int> poi[maxn];
        
int allx[maxn],ally[maxn];
int yey[maxn];

int k;
LL C(int n,int m){
    if(m > n) return 0;
    return comb[n][m];
}
LL calC(int all,int sub){
    return (C(sub,k)*C(all-sub,k)) & mod;
}

void update(int pos){
    upd(pos,-1*calC(ally[pos],yey[pos]) );
    yey[pos]++;
    upd(pos,calC(ally[pos],yey[pos]));
}
LL query(int l,int r){
    if(r<l) return 0;
    return que(r) - que(l-1);
}
LL cal(int n){
    Mx.done(),My.done();
    memset(allx,0,sizeof(allx));
    memset(ally,0,sizeof(ally));
    for(int i=0;i<n;i++){
        Mx.upd(poi[i].first);
        My.upd(poi[i].second);
        allx[poi[i].first]++,ally[poi[i].second]++;
    }
    sort(poi,poi+n);
    LL ans = 0;
    memset(yey,0,sizeof(yey));
    int cnt;
    for(int i=0;i<n;i++){
        if(i==0 || poi[i].first != poi[i-1].first){
            cnt = 1;
        }
        else{
            (ans += (calC(allx[poi[i].first],cnt)*query(poi[i-1].second+1,poi[i].second-1)) & mod )&= mod;
            cnt++;
        }
        update(poi[i].second);
    }
    return ans;
}
int main(){
    int n,m;
    initC();
    while(~scanf("%d %d",&n,&m)){
        int x,y;
        Mx.init(),My.init();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            poi[i] = make_pair(x,y);
            Mx.add(x),My.add(y);
        }
        scanf("%d",&k);
        printf("%lld\n",cal(n));
    }
    return 0;
}
        
