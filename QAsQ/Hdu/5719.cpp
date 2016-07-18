#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long

const int maxn = 112345;
const int mod = 998244353;

int arr[maxn];

int lowbit(int x){
    return x & (-x);
}

int upd(int x){
    while(x<maxn){
        arr[x]++;
        x += lowbit(x);
    }
}

LL sum(int x){
    LL ret = 0;
    while(x){
        ret += arr[x];
        x -= lowbit(x);
    }
    return ret;
}

int mi[maxn],ma[maxn];

LL cal(int n){
    LL ans = 1;
    memset(arr,0,sizeof(arr));
    if(mi[1] != ma[1]) return 0;
    upd(mi[1]);
    for(int i=2;i<=n;i++){
        if(mi[i] > mi[i-1]) return 0;
        if(ma[i] < ma[i-1]) return 0;
        int v = mi[i]!=mi[i-1];
        v += ma[i]!=ma[i-1];
        if(v == 2)
            return false;
        if(v == 0){
            (ans = ans *(0ll + ma[i] - mi[i] + 1 - (sum(ma[i]) - sum(mi[i]-1) ) ) ) %= mod;
            upd(mi[i]);
        }
        else{
            int v = mi[i] == mi[i-1] ? ma[i] : mi[i];
            upd(v);
        }
    }
    return ans;
}


int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&mi[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&ma[i]);
        }
        printf("%I64d\n",cal(n));
    }
    return 0;
}
