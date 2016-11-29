#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

char arr[maxn];

bool all(int n,char c){
    for(int i = 1; i <= n ; i ++){
        if(arr[i] != '.' && arr[i] != c) 
            return false;
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    scanf("%s",arr+1);
    arr[0] = arr[n+1] = '.';
    int s,t;
    s = t = -1;
    if(all(n,'L') || all(n,'R')){
        for(int i = 1; i <= n ; i ++){
            if(arr[i-1] == '.' && arr[i] != '.') 
                s = i;
            if(arr[i+1] == '.' && arr[i] != '.') 
                t = i;
        }
        if(arr[s] == 'R'){
            t++;
        }
        else{
            swap(s,t);
            t--;
        }
    }else{
        for(int i = 1; i <= n ; i ++){
            if(arr[i-1] == '.' && arr[i] == 'R') s = i;
            if(arr[i] == 'R' && arr[i+1] == 'L') t = i;
        }
    }
    printf("%d %d\n",s,t);
    return 0;
}
