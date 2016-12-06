#include<bits/stdc++.h>
using namespace std;

const int maxn = 312;
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
int n;

struct Mar{
    LL mp[maxn][maxn];
    void clear(){
        for(int i = 1; i <= n ; i ++)
            for(int j = 1; j <= n ; j ++)
                mp[i][j] = -INFF * ( i != j);
    }
    bool check(){
        for(int i = 1; i <= n ; i ++)
            if(mp[i][i] > 0) return true;
        return false;
    }
};

Mar operator *(const Mar & a,const Mar & b){
    Mar ret;
    ret.clear();
    for(int k = 1; k <= n ; k ++)
        for(int i = 1; i <= n ; i ++)
            for(int j = 1; j <= n ; j ++)
                ret.mp[i][j] = max(ret.mp[i][j],a.mp[i][k] + b.mp[k][j]);
    return ret;
}

Mar mp[10];
Mar tem,bas;

LL cal(){
    if(mp[9].check() == false) return 0;
    int st = 0;
    while(mp[st].check() == false){ 
        st++;
    }
    st--;
    LL ans = 1ll << st;
    bas = mp[st];
    while(st >= 0){
        tem = bas * mp[st];
        if(tem.check() == false){
            ans += 1ll << st;
            bas = tem;
        }
        st--;
    }
    return ans + 1;
}

int main(){
    int m;
    scanf("%d %d",&n,&m);
    int l,r,v;
    mp[0].clear();
    while(m--){
        scanf("%d %d %d",&l,&r,&v);
        mp[0].mp[l][r] = max(mp[0].mp[l][r],v * 1ll);
        scanf("%d",&v);
        mp[0].mp[r][l] = max(mp[0].mp[r][l],v * 1ll);
    }
    for(int i = 1; i < 10 ; i ++)
        mp[i] = mp[i-1] * mp[i-1];
    printf("%I64d\n",cal());
    return 0;
}

