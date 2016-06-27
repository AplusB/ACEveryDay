#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
int a[maxn];
LL sum[1 << 6], all;
bool isp[maxn];
vector < int > p;
vector < int > fac;

void init(){
    memset(isp, true, sizeof isp);
    for(int i = 2; i < maxn; i++){
        if(isp[i]) p.push_back(i);
        for(int j = 0; j < p.size() && (LL)i * p[j] < maxn; j++){
            isp[i * p[j]] = false;
            if(i % p[j] == 0) break;
        }
    }
}

void get_fac(int n){
    fac.clear();
    for(int i = 0; i < p.size() && (LL)p[i] * p[i] <= n; i++){
        if(n % p[i] == 0){
            fac.push_back(p[i]);
            while(n % p[i] == 0) n /= p[i];
        }
    }
    if(n > 1) fac.push_back(n);
}

void update(int n, int sgn){
    get_fac(n);
    int sz = fac.size();
    for(int mask = 1; mask < (1 << sz); mask++){
        int mul = 1;
        for(int i = 0; i < sz; i++){
            if(mask & (1 << i)){
                mul *= fac[i];
            }
        }
        sum[mul] += sgn * a[n];
    }
    all += sgn * a[n];
}

LL count(int n){
    get_fac(n);
    LL ans = 0;
    int sz = fac.size();
    for(int mask = 1; mask < (1 << sz); mask++){
        int mul = 1, cnt = 0;
        for(int i = 0; i < sz; i++){
            if(mask & (1 << i)){
                mul *= fac[i];
                cnt++;
            }
        }
        if(cnt & 1) ans += sum[mul];
        else ans -= sum[mul];
    }
    return all - ans;
}

int main(){
    int n, q, ope, pos, b;
    init();
    scanf("%d%d", &n, &q);
    all = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        update(i, 1);
    }
    while(q--){
        scanf("%d", &ope);
        if(ope == 1){
            scanf("%d%d", &pos, &b);
            update(pos, -1);
            a[pos] = b;
            update(pos, 1);
        }else{
            scanf("%d", &pos);
            printf("%lld\n", count(pos));
        }
    }
    return 0;
}
