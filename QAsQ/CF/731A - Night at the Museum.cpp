#include<bits/stdc++.h>
using namespace std;

const int maxn = 112;

char arr[maxn];

int num(char bef,char aft){
    return min(abs(bef-aft),min(abs(bef+26-aft),abs(aft+26-bef)));
}

int main(){
    scanf("%s",arr);
    int ret = num('a',arr[0]);
    for(int i=1;arr[i];i++){
        ret += num(arr[i-1],arr[i]);
    }
    printf("%d\n",ret);
    return 0;
}
