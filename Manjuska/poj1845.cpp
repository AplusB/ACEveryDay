#include<iostream>
#include<stdio.h>
using namespace std;
const int Mod = 9901;
const int Max = 10000;
typedef __int64 LL;

int A, B;
int pri[Max], cnt[Max];
 
LL pow(LL p, LL n){     
    LL sum = 1;
    while(n > 0){
        if(n & 1)
            sum = (sum * p) % Mod;
        n >>= 1;
        p = p * p % Mod;
    }
    return sum;
}
 
LL sum(LL p, LL n){     
    if(n == 0) return 1;
    if(n & 1)
        return ((1+pow(p, n/2+1)) * sum(p, n/2)) % Mod;
    else
        return ((1+pow(p, n/2+1)) * sum(p, n/2-1) + pow(p, n/2)) % Mod;
}
 
int main(){
    int i, k;
    scanf("%d%d", &A, &B);
    for(k = 0, i = 2; i * i <= A; i ++)  
        if(A % i == 0){ 
            pri[k] = i;
            while(A % i == 0){
                cnt[k] ++;
                A /= i;
            }
            k ++;
        }
    if(A != 1){        
        pri[k] = A;
        cnt[k ++] = 1;
    }
    int ans = 1;
    for(i = 0; i < k; i ++)
        ans = ans * (sum(pri[i], cnt[i] * B) % Mod) % Mod;
    printf("%d\n", ans);
    return 0;
}
