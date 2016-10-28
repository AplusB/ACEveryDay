#include<bits/stdc++.h>
using namespace std;

set<int> S;
int main(){
    int a,b,n;
    int x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        S.insert(x);
    }
    scanf("%d %d",&a,&b);
    int tim = 0;
    while(a != b){
        int mi = a - 1;
        for(set<int>::iterator it = S.begin();it != S.end(); ){
            int x = *it;
            it++;
            if(a - a % x < b) S.erase(x);
            else mi = min(mi,a - a % x);
        }
        a = mi;
        tim++;
    }
    printf("%d\n",tim);
    return 0;
}
