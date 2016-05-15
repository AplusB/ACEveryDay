/*
    一开始用的结构体，然后暴力超时，现学了一发map，暴力水过。
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm> 
#include<map>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(i=a;i<b;i++)
int n,m,i,l;
char aa[111];
map<string,int>ma;

int main(){
    scanf("%d",&n);
    while(n--){
        string ss;
        scanf("%s",aa);
        l=strlen(aa);
        sort(aa,aa+l);
        rep(i,0,l)ss+=aa[i];
        ma[ss]++;
        printf("%d\n",ma[ss]-1);
    }
    return 0;
}
