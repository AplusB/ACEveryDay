#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int arr[maxn],tim[maxn],tem[maxn];
int anw[maxn],n;

bool check(int x){
    memcpy(tem,arr,sizeof(arr));
    for(int i=0;i<n;i+=x){
        sort(tem + i,tem + i + x);
        for(int j=0;j<x;j++)
            if(tem[j] != tem[j+i]) return false;
    }
    return true;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d",&n)){
        memset(tim,0,sizeof(tim));
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
            tim[arr[i]]++;
        }
        int ans = n;
        for(int i=1;i<=n;i++){
            if(tim[i])
                ans = __gcd(ans,tim[i]);
        }
        int len = 0;
        for(int i=1;i*i<=ans;i++){
            if(ans % i == 0){
                if(check(n / i))
                    anw[len++] = n / i;
                if(i * i != ans){
                    if(check(n / (ans / i)))
                        anw[len++] = n / (ans / i);
                }
            }
        }
        sort(anw,anw+len);
        for(int i=0;i<len;i++)
            printf(i<len-1?"%d ":"%d\n",anw[i]);
    }
    return 0;
}
