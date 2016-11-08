#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
#define LL long long 

char arr[maxn],brr[maxn];
int an,bn;

int cnt[maxn][26];

int main(){
    ios::sync_with_stdio(false);
    LL n,m;
    cin>>n>>m;
    cin>>arr>>brr;
    LL an = strlen(arr),bn = strlen(brr);
    LL g = __gcd(an,bn);
    memset(cnt,0,sizeof(cnt));
    for(int i = 0 ; i < an;i++){
        cnt[i % g][arr[i] - 'a']++;
    }
    LL ans = an / g * bn;
    for(int i = 0 ; i < bn;i++){
        ans -= cnt[i % g][brr[i] - 'a'];
    }
    ans = ans * (n / (bn / g));
    cout<<ans<<endl;
    return 0;
}
