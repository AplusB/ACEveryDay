#include <bits/stdc++.h>
using namespace std;

int main(){
    int w, m;
    scanf("%d%d", &w, &m);
    if(w == 2 || w == 3){
        puts("YES");
        return 0;
    }
    int flag = 0;
    for(int bit; m; m /= w){
        bit = m % w;
        if(bit == w - 2 && flag) continue;
        if(1 < bit && bit < w - 1 || bit == 1 && flag){
            puts("NO");
            return 0;
        }
        if(bit == 0) flag = 0;
        if(bit == w - 1) flag = 1;
    }
    puts("YES");
    return 0;
}
