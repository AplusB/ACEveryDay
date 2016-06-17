#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#define LL long long 

const int maxn = 112345;
int arr[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr+1,arr+1+n);
    int ans = 1;
    for(int i=1;i<=n;i++){
        if(arr[i] >= ans)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}

