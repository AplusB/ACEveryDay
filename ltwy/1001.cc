#include <bits/stdc++.h>
using namespace std;
int T;
 
int main() {
    cin>>T;
    int x;
    int icase = 0;
    while(T--) {
        scanf("%d", &x);
        if(x <= 10)
            printf("%d %d\n", x, 0);
        else
            printf("%d %d\n", 10, x - 10);
    }
    return 0;
}