#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345;
#define LL long long 

LL b[maxn],c[maxn];
LL a[maxn];

int cnt[50];
void icnt(LL x){
    int len = 0;
    while(x){
        cnt[len++] += x & 1;
        x >>= 1;
    }
}

bool check(int n){
    LL asum = 0;
    for(int i = 1; i <= n;i++) asum += b[i] + c[i];
    if(asum % (n * 2) != 0) return false;
    asum /= n * 2;
    memset(cnt,0,sizeof(cnt));
    for(int i = 1; i <= n;i++){
        if(b[i] + c[i] < asum) return false;
        a[i] = b[i] + c[i] - asum;
        if(a[i] % n != 0) return false;
        a[i] /= n;
        icnt(a[i]);
    }
    for(int i = 1; i <= n;i++){
        LL tb = 0,tc = 0;
        for(int j = 0 ; j < 40;j ++){
            tc += (1 << j) * cnt[j];
            if((a[i]>>j) & 1){
                tc += (1 << j) * (n - cnt[j]);
                tb += (1 << j) * cnt[j];
            }
        }
        if(b[i] != tb || c[i] != tc) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1; i <= n;i++) cin >> b[i];
    for(int i = 1; i <= n;i++) cin >> c[i];
    if(check(n) == false){
        cout<<-1<<endl;
    }
    else{
        for(int i = 1; i <= n;i++){
            cout<<a[i];
            if(i != n) cout<<" ";
        }
    }
}
