#include<bits/stdc++.h>
using namespace std;

const int maxn = 5123;

int r[maxn],c[maxn];
int rt[maxn],ct[maxn];

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    memset(rt,0,sizeof(rt));
    memset(ct,0,sizeof(ct));
    int p,v,o;
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&o,&p,&v);
        if(o==1){
            r[p] = v,rt[p] = i;
        }
        else{
            c[p] = v,ct[p] = i;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int v = r[i];
            if(ct[j] > rt[i]) v = c[j];
            printf(j<m?"%d ":"%d\n",v);
        }
    }
    return 0;
}


