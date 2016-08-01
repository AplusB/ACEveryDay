#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int arr[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    int ans = 1;
    int ed = 1;
    for(int i=1;i<=n;i++){
        if(ed < i) ed = i;
        while(ed < n && arr[ed] < arr[ed+1])
            ed++;
        ans = max(ans,ed-i+1);
    }
    printf("%d\n",ans);
    return 0;
}
