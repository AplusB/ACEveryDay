#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
int arr[maxn * 2];

void shift(int st,int ed){
    arr[ed+1] = arr[st];
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
        arr[i] = i;
    int st = 1,ed = n;
    for(int k=2;k<=n;k++){
        shift(ed - n % k + 1,ed);
        int pos = ed - n % k + 1;
        while(pos - k >= st){
            arr[pos] = arr[pos-k];
            pos -= k;
        }
        st++,ed++;
    }
    for(int i = st;i<=ed;i++){
        printf(i<ed?"%d ":"%d\n",arr[i]);
    }
    return 0;
}



