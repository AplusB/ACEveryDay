#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
#define LL long long 

LL arr[maxn], stv[maxn];
vector<int> rev[maxn],seter[maxn],big;
bitset<maxn> hav[400];
LL add[maxn];
int ctb[maxn][400], id[maxn];

int main(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i<=n;i++) scanf("%I64d",&arr[i]);

    int len, allsiz = 0;
    for(int i = 1;i<=m;i++){
        scanf("%d",&len);
        allsiz += len;
        id[i] = -1;
        add[i] = stv[i] = 0;
        int x;
        while(len--){
            scanf("%d",&x);
            seter[i].push_back(x);
            stv[i] += arr[x];
        }
    }
    int unit = (int)sqrt(allsiz * 1.0) + 1;
    for(int i = 1;i<=m;i++){
        if(seter[i].size() >= unit){
            id[i] = big.size();
            big.push_back(i);
            for(auto x : seter[i]){
                hav[id[i]][x] = 1;
                rev[x].push_back(id[i]);
            }
        }
    }
    memset(ctb,0,sizeof(ctb));
    for(int i = 1;i<=m;i++){
        for(auto x : seter[i]){
            for(auto loca : rev[x]){
                ctb[i][loca]++;
            }
        }
    }
    char ord[3];
    int k;
    LL v;
    while(q--){
        scanf("%s %d",ord,&k);
        if(*ord == '?'){
            LL ans = 0;
            if(id[k] == -1) for(auto x : seter[k]) ans += arr[x];
            else ans = stv[k];
            for(auto x : big){
                ans += add[x] * ctb[k][id[x]];
                //printf("ader %I64d %d\n",add[x],ctb[k][id[x]]);
            }
            printf("%I64d\n",ans);
        }
        else{
            scanf("%I64d",&v);
            if(id[k] != -1) add[k] += v;
            else{
                for(auto x : seter[k]) arr[x] += v;
                for(auto x : big ){
                    stv[x] += v * ctb[k][id[x]];
                }
            }
        }
    }
    return 0;
}

