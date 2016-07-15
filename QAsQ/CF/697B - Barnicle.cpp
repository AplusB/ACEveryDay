#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 125;
char d[maxn];

bool allzero(char *s){
    for(int i=0;s[i];i++){
        if(s[i]!='0') return false;
    }
    return true;
}
      

int main(){
    int a,b;
    for(int i=0;i<maxn;i++){
        d[i] = '0';
    }
    d[maxn-1] = 0;
    scanf("%d.%[0-9]e%d",&a,d+1,&b);
    d[0] = a + '0';
    d[strlen(d)] = '0';
    int pos = 0;
    while(pos < b && d[pos] == '0')
        pos++;
    for(int i=pos;i<=b;i++){
        printf("%c",d[i]);
    }
    if(!allzero(d+b+1)){
        printf(".");
        pos = b + 1;
        while(!allzero(d+pos)){
            printf("%c",d[pos]);
            pos++;
        }
    }
    puts("");
    return 0;
}
