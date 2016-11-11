#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const LL INFF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 112345;

LL rx,ry;

struct Point{
    LL x,y;
    void in(){
        scanf("%lld %lld",&x,&y);
        x -= rx,y -= ry;
        LL g = __gcd(abs(x),abs(y));
        x /= g,y /= g;
    }
}arr[maxn];
set<pair<LL,LL> > S;

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%lld %lld %d",&rx,&ry,&n)){
        S.clear();
        for(int i = 0 ; i < n;i++){
            arr[i].in();
        }
        for(int i = 0 ; i < n;i++){
            S.insert(make_pair(arr[i].x,arr[i].y));
        }
        printf("%d\n",S.size());
    }
    return 0;
}
