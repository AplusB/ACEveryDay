#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        int ans = 0;
        while(m && n){
            ans += n % 2;
            n >>= 1;
            m--;
        }
        ans += n;
        printf("%d\n",ans);
    }
    return 0;
}
