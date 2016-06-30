#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5000005;
bool notp[maxn];
int p[350000], E[maxn];
LL sum[maxn];

void init(){
    E[1] = 1;
    int tol = 0;
    for(int i = 2; i < maxn; i++){
        if(!notp[i]){
            p[tol++] = i;
            E[i] = i - 1;
        }
        for(int j = 0; j < tol && (LL)i * p[j] < maxn; j++){
            notp[i * p[j]] = true;
            if(i % p[j] == 0){
                E[i * p[j]] = E[i] * p[j];
                break;
            }else{
                E[i * p[j]] = E[i] * (p[j] - 1);
            }
        }
    }
    int UP = sqrt(1.0 * maxn);
    for(int i = 1; i <= UP; i++){
        for(int j = i * (i + 1); j < maxn; j += i){
            sum[j] += (LL)i * E[j / i];
            if(i != 1)
            sum[j] += (LL)j / i * E[i];
        }
        sum[i * i] += (LL)i * E[i];
    }
    sum[1] = 0;
    for(int i = 1; i < maxn; i++){
        sum[i] += sum[i - 1];
    }
}

void out(LL x){
    if(!x) return;
    out(x / 10);
    putchar(x % 10 + '0');
}

int main(){
    init();
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        out(sum[n]);
        puts("");
    }
    return 0;
}
