#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1123456;
bool vis[maxn];
int pri[maxn],plen;

int sieve(){
    memset(vis,0,sizeof(vis));
    plen = 0;
    for(int i=2;i<maxn;i++){
        if(vis[i] == false){
            pri[plen++] = i;
            for(int j=i*2;j<maxn;j+=i)
                vis[j] = true;
        }
    }
    return plen;
}

int main(){
    int v = sieve();
    int T;
    scanf("%d",&T);
    int n,p;
    while(T-- && ~scanf("%d %d",&n,&p)){
        n--;
        int t = n / p;
        int pos = 0;
        if(t <= 1){
            puts("0");
            continue;
        }
        if(p%2==0){
            pos = p*2<=n;
        }
        else{
            pos = 1;
            while(pri[pos] <= t && p%pri[pos-1]!=0 && pos < v)
                pos++;
        }
        printf("%d\n",pos);
    }
    return 0;
}
