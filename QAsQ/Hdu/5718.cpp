#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 11234567;
char arr[maxn];

bool judge(){
    int ret = 0;
    for(int i=0;arr[i];i++){
        ret += arr[i] != '0';
    }
    return ret != 1;
}

int geter(){
    int pos = 0;
    while(arr[pos] == '0')
        pos++;
    int ret = arr[pos] - '0';
    for(int i=pos;arr[i];i++){
        arr[i] = arr[i+1];
    }
    return ret;
}


int main(){
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%s",arr)){
        if(!judge()){
            puts("Uncertain");
            continue;
        }
        int len = strlen(arr);
        sort(arr,arr+len);
        int t = geter();
        len--;
        arr[len] = '0';
        int pos = 0;
        arr[pos] += t;
        while(arr[pos] > '9'){
            arr[pos]-=10;
            arr[pos+1]++;
            pos++;
        }
        if(pos == len) len++;
        arr[len] = 0;
        reverse(arr,arr+len);
        printf("%s\n",arr);
    }
    return 0;
}
