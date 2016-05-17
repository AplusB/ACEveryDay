#include <bits/stdc++.h>
using namespace std;
int T;
 
int main() {
    cin>>T;
    int a, b;
    int icase = 0;
    while(T--) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", ++icase, a + b);
    }
    return 0;
}
