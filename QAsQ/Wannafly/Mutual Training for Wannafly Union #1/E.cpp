#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
map<int,vector<pair<int,LL> > > dig,rdig;

LL msp[maxn * 2],mlen;
int arr[maxn * 2],dp[maxn];

int lowbit(int x){ return x & (-x);}
int que(int pos){
    int ret = 0;
    while(pos) ret = max(ret,arr[pos]),pos -= lowbit(pos);
    return ret;
}
void upd(int pos,int v){
    while(pos < maxn * 2) arr[pos] = max(arr[pos],v),pos += lowbit(pos);
}

int getpos(LL v){
    return lower_bound(msp,msp+mlen,v) - msp;
}

int cal(vector<pair<int,LL> > & vec,int c){
    mlen = 0;
    for(auto v : vec){
        msp[mlen++] = v.first - v.second; 
        msp[mlen++] = v.first + v.second + c - 1;
    }
    msp[mlen++] = -INFF;
    sort(msp,msp+mlen);
    mlen = unique(msp,msp+mlen) - msp;
    sort(vec.begin(),vec.end());
    for(int i = 0 ; i <= mlen ; i ++) arr[i] = 0;
    dp[0] = 0;
    int pos = 1;
    for(auto v : vec){
        dp[pos] = que(getpos(v.first - v.second)) + 1;
        upd(getpos(v.first + v.second + c - 1),dp[pos]);
        pos++;
    }
    return *max_element(dp,dp+pos);
}

int main(){
    freopen("bishops.in","r",stdin);
    int T;
    scanf("%d",&T);
    int m, n ,C;
    while(T-- && ~scanf("%d",&n)){
        scanf("%d %d",&m,&C);
        dig.clear(),rdig.clear();
        int x,y;
        LL p;
        while(m--){
            scanf("%d %d %I64d",&x,&y,&p);
            dig[x + y].push_back(make_pair(x,p * p));
            rdig[x - y].push_back(make_pair(x,p * p));
        }
        int ans = 0;
        for(auto vec : dig) ans = max(ans,cal(vec.second,C));
        for(auto vec : rdig) ans = max(ans,cal(vec.second,C));
        printf("%d\n",ans);
    }
    return 0;
}
