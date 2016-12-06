#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
int arr[maxn];
#define LL long long 

int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    memset(arr,0,sizeof(arr));
    int v;
    LL ans = 0;
    while(n--){
        scanf("%d",&v);
        ans += arr[v ^ x];
        arr[v]++;
    }
    printf("%I64d\n",ans);
    return 0;
}
