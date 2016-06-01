#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 11234;
const int mod = 10007;

vector<int> fac[maxn];
int mu[maxn];

void init(){
    memset(mu,0,sizeof(mu));
    mu[1] = 1;
    for(int i=1;i<maxn;i++){
        for(int j=i;j<maxn;j+=i){
            fac[j].push_back(i);
            if(j!=i) mu[j] -= mu[i];
        }
    }
    for(int i=1;i<10;i++){
        printf("%d\n",mu[i]);
    }
}

int cnt[maxn];

int main(){
    init();
    int n;
    while(~scanf("%d",&n)){
        memset(cnt,0,sizeof(cnt));
        int x;
        while(n--){
            scanf("%d",&x);
            for(vector<int>::iterator it = fac[x].begin();it!=fac[x].end();it++){
                cnt[*it]++;
            }
        }
        int ret = 0;
        for(int i=1;i<maxn;i++){
            int tim = 0;
            for(int j=i;j<maxn;j+=i){
                (tim += mu[j/i]*cnt[j] ) %= mod;
            }
            ret += tim * i % mod * (i-1);
            ret %= mod;
            if(i<10){
                printf("i = %d tim = %d\n",i,tim);
            }
        }
        printf("%d\n",ret);
    }
    return 0;
}
