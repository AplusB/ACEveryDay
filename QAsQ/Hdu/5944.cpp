#include <bits/stdc++.h>
using namespace std;
const int maxn = 11234;
char arr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%s",arr+1)){
        int ans = 0;
        int len = strlen(arr+1);
        for(int i = 1; arr[i];i++){
            if(arr[i] != 'y') continue;
            for(int j = 2;i * j * j <= len;j++){
                if(arr[j*i] != 'r') continue;
                ans += arr[i*j*j] == 'x';
            }
        }
        for(int i = 1; arr[i];i++){
            if(arr[i] != 'x') continue;
            for(int j = 2;i * j * j <= len;j++){
                if(arr[j*i] != 'r') continue;
                ans += arr[i*j*j] == 'y';
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
