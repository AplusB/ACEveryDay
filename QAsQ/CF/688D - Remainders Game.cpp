#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 1123456;
const int bnc = 1000000;

vector<int> fac[maxn];

bool vis[maxn];
int prim[maxn],plen;

void init(){
    memset(vis,0,sizeof(vis));
    plen = 0;
    for(int i=2;i<=bnc;i++){
        if(vis[i] == false){
            prim[plen++] = i;
            for(int j=i*2;j<=bnc;j+=i){
                vis[j] = true;
            }
        }
    }
    for(int i=0;i<plen;i++){
        for(LL k = prim[i];k <= bnc;k *= prim[i]){
            for(int j=k;j<=bnc;j+=k){
              fac[j].push_back(k);
            }
        }
    }
}


bool judge(int k){
    int pos = 0;
    while(k!=1){
        if(k %prim[pos]==0){
            int p = prim[pos];
            int lef = 1;
            while(k%p==0){
                k/=p;
                lef *= p;
            }
            if(vis[lef] == false) return false;
        }
        pos++;
    }
    return true;
}

int main(){
    int n,k;
    init();
    scanf("%d %d",&n,&k);
    int st;
    memset(vis,0,sizeof(vis));
    while(n--){
        scanf("%d",&st);
        for(auto x : fac[st]){
            vis[x] = true;
        }
    }
    puts(judge(k)?"Yes":"No");
    return 0;
}

