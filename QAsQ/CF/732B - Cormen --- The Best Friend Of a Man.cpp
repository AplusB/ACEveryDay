#include<bits/stdc++.h>
using namespace std;

const int maxn = 550;
int arr[maxn],ans[maxn];

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sumer = 0;
    ans[0] = arr[0];
    for(int i=1;i<n;i++){
        int v = arr[i] + ans[i-1];
        if(v < k){
            sumer += k - v;
            ans[i] = k - ans[i-1];
        }
        else{
            ans[i] = arr[i];
        }
    }
    printf("%d\n",sumer);
    for(int i=0;i<n;i++){
        printf(i<n-1?"%d ":"%d\n",ans[i]);
    }
    return 0;
}
