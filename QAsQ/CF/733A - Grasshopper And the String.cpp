#include<bits/stdc++.h>
using namespace std;

const char m[] = "AEIOUY";

bool is(char c){
    for(int i =0;m[i];i++) if(m[i] == c) return true;
    return false;
}

const int maxn = 300;
char arr[maxn];

int main(){
    scanf("%s",arr);
    int st = -1;
    int ans = 1;
    for(int i = 0;arr[i];i++){
        if(is(arr[i])){
            ans = max(ans,i - st);
            st = i;
        }
    }
    ans = max(ans,(int)strlen(arr) - st);
    printf("%d\n",ans);
    return 0;
}
