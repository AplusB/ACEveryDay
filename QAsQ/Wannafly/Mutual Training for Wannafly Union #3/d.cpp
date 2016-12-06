#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 212345;

void getFail(LL *p,int *f,int m){
    f[0] = 0,f[1] = 0;
    p[m] = INFF;
    for(int i = 1 ; i <= m ; i++){
        int j = f[i];
        while(j && p[i] != p[j]) j = f[j];
        f[i+1] = p[i] == p[j] ? j + 1 : 0;
    }
}

int fnd(LL *t,LL *p,int *f,int n,int m){
    int j = 0;
    int ret = 0;
    for(int i = 0 ; i < n ; i ++){
        while(j && p[j] != t[i]) j = f[j];
        if(p[j] == t[i]) j++;
        if(j == m){ 
            ret++; 
            j = f[j];
        }
    }
    return ret;
}

LL a[maxn],b[maxn];
int nex[maxn];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i ++) scanf("%I64d",&a[i]);
    for(int i = 0 ; i < m ; i ++) scanf("%I64d",&b[i]);
    n--,m--;
    for(int i = 0 ; i < n ; i ++) a[i] -= a[i+1];
    for(int i = 0 ; i < m ; i ++) b[i] -= b[i+1];
    getFail(b,nex,m);
    printf("%d\n",m == 0 ? n + 1 : fnd(a,b,nex,n,m));
    return 0;
}
