#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const int maxn = 112345;
int l[maxn],r[maxn];

int main(){
    int n ;
    scanf("%d",&n);
    int L = 0,R = 0;
    for(int i = 0;i<n;i++){
        scanf("%d %d",&l[i],&r[i]);
        L += l[i], R += r[i];
    }
    int ans = abs(L-R),v = 0;
    for(int i = 0;i < n;i++){
        int nl = L - l[i] + r[i];
        int nr = R - r[i] + l[i];
        if(ans < abs(nl-nr)){
            ans = max(ans,abs(nl-nr));
            v = i + 1;
        }
    }
    printf("%d\n",v);
    return 0;
}

