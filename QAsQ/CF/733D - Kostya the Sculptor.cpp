#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;
LL x[maxn],y[maxn],z[maxn];

map<pair<LL,LL>,int > M;

LL calv(pair<LL,LL> s,LL v,LL *t){
    v += t[M[s]];
    v = min(v,min(s.first,s.second));
    return v >> 1;
}

int main(){
    int n;
    scanf("%d",&n);
    LL a,b,c;
    LL ma = 0;
    int pos = -1;
    x[0] = y[0] = z[0] = 0;
    for(int i = 1; i <= n;i++){
        scanf("%I64d %I64d %I64d",&a,&b,&c);
        a <<= 1,b <<= 1,c <<= 1;
        x[i] = max(a,max(b,c));
        z[i] = min(a,min(b,c));
        y[i] = a + b + c - x[i] - z[i];
        if(ma < (z[i] >> 1)){
            ma = z[i] >> 1;
            pos = i;
        }
    }
    int por = -1;
    for(int i = 1;i <= n;i++){
        pair<LL,LL> s = make_pair(x[i],y[i]);
        pair<LL,LL> t = make_pair(x[i],z[i]);
        pair<LL,LL> v = make_pair(y[i],z[i]);
        if(ma < calv(s,z[i],z)){
            ma = calv(s,z[i],z);
            pos = M[s],por = i;
        }
        if(ma < calv(t,y[i],y)){
            ma = calv(t,y[i],y);
            pos = M[t],por = i;
        }
        if(ma < calv(v,x[i],x)){
            ma = calv(v,x[i],x);
            pos = M[v],por = i;
        }
        if(z[M[s]] < z[i]) M[s] = i;
        if(y[M[t]] < y[i]) M[t] = i;
        if(x[M[v]] < x[i]) M[v] = i;
    }
    if(por == -1){
        printf("%d\n%d\n",1,pos);
    }
    else{
        printf("%d\n%d %d\n",2,pos,por);
    }
    return 0;
}
