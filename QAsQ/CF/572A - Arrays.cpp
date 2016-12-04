#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int a[maxn],b[maxn];
int main(){
    int an,bn,m,k;
    scanf("%d %d",&an,&bn);
    scanf("%d %d",&k,&m);
    for(int i = 0 ; i < an; i ++) scanf("%d",&a[i]);
    for(int i = 0 ; i < bn; i ++) scanf("%d",&b[i]);
    sort(a,a+an);
    sort(b,b+bn,[](int a,int b){return a > b;});
    puts(a[k-1] < b[m-1] ?  "YES":"NO");
    return 0;
}
