#include<bits/stdc++.h>
using namespace std;
#define LL long long 

void cal(LL &x,LL &y,LL a,LL b){
    if(a * a < 4 * b) return;
    LL sq = (LL)sqrt(a * a - 4 * b);
    if(sq * sq != a * a - 4 * b) return;
    if((a + sq)  & 1) return;
    sq = (a + sq)/2;
    x =  sq,y = a-sq;
    if(y < 0) x = y = -1;
}

int main(){
    LL a,b;
    while(~scanf("%I64d %I64d",&a,&b)){
        LL x,y;
        x = y = -1;
        LL g = __gcd(a,b);
        a /= g,b /= g;
        cal(x,y,a,b);
        if(x > y) swap(x,y);
        if(x == -1) puts("No Solution");
        else printf("%I64d %I64d\n",x * g,y * g);
    }
    return 0;
}
