#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

void fwt (LL a[] , int n ,bool on) {
    for ( int d = 1 ; d < n ; d <<= 1 ) {
        for ( int k = d << 1 , i = 0 ; i < n ; i += k ) {
            for ( int j = 0 ; j < d ; ++ j ) {
                LL x = a[i + j] , y = a[i + j + d] ;
                if(on){
                    a[i + j] = ( x + y )  ;
                    a[i + j + d] = ( x - y  )  ;
                }
                else{
                    a[i + j] = ( x + y ) / 2 ;
                    a[i + j + d] = ( x - y ) / 2;
                }
            }
        }
    }
}

char inp[22][maxn];
int arr[maxn];
LL A[1<<22],B[1<<22];

int getone(int x,int n){
    int ret = 0 ;
    while(x){
        ret += x & 1;
        x >>= 1;
    }
    return min(ret,n - ret);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n; i ++) scanf("%s",inp[i]);
    for(int i = 0 ; i < m ; i++){
        arr[i] = 0;
        for(int j = 0 ; j < n ; j ++){
            arr[i] |= (inp[j][i] - '0') << j;
        }
    }
    memset(A,0,sizeof(A));
    for(int i = 0 ; i < m ; i++) A[arr[i]] ++;
    for(int i = 0 ; i < (1<<n) ; i ++){
        B[i] = getone(i,n);
    }
    fwt(A,1<<n,true);
    fwt(B,1<<n,true);
    for(int i = 0; i < (1<<n);i++) A[i] *= B[i];
    fwt(A,1<<n,false);
    LL ans = INFF;
    for(int i = 0 ; i < (1<<n);i++) ans = min(ans,A[i]);
    printf("%I64d\n",ans);
    return 0;
}
