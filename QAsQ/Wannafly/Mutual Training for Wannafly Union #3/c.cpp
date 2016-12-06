#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

int a[3];

int main(){
    int n;
    scanf("%d",&n);
    int x;
    memset(a,0,sizeof(a));
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&x);
        a[i % 3] += x;
    }
    int ma = max_element(a,a+3) - a;
    if(ma == 0){
        puts("chest");
    }else if(ma == 1){
        puts("biceps");
    }else{
        puts("back");
    }
    return 0;
}
