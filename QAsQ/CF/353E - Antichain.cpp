#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;

char inp[maxn];
int arr[maxn];


int main(){
    scanf("%s",inp);
    int len = strlen(inp);
    int n = 0;
    for(int i = 0 ; i < len;i++){
        if(i==0 || inp[i] != inp[i-1]) arr[n++] = 1;
        else arr[n-1]++;
    }
    if(inp[0] == inp[len-1]) 
        arr[0] += arr[n-1],n--;
    int ans = 0,cnt = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 1) cnt++;
        else{
            ans += cnt / 2 + 1;
            cnt = 0;
        }
    }
    ans += cnt / 2;
    printf("%d\n",ans);
    return 0;
}
