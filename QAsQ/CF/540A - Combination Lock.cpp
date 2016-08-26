#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

char arr[maxn],brr[maxn];

int calans(int x,int y){
    return min(abs(x-y),min(abs(y+10-x),abs(x+10-y)));
}

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s %s",arr,brr);
    int ret = 0;
    for(int i=0;i<n;i++){
        ret += calans(arr[i] - '0',brr[i] - '0'); 
    }
    printf("%d\n",ret);
    return 0;
}
