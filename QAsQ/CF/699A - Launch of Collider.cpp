#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 212345;
const int INF = 0x3f3f3f3f;
char arr[maxn];
int brr[maxn];

int cal(int n){
    int ret = INF;
    for(int i=1;i<n;i++){
        if(arr[i-1] == 'R' && arr[i] == 'L')
            ret = min(ret,(brr[i]-brr[i-1])/2);
    }
    return ret == INF ? -1 : ret;
}
int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",arr);
    for(int i=0;i<n;i++){
        scanf("%d",&brr[i]);
    }
    printf("%d\n",cal(n));
    return 0;
}
