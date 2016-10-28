//Codeforces Round #348 (VK Cup 2016 Round 2, Div. 2 Edition)
//D - Little Artem and Dance
#include <bits/stdc++.h>
using namespace std;
int n,q,x;
int main(){
    int a=0,b=0;
    scanf("%d%d",&n,&q);
    while(q--){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1){
            scanf("%d",&x);
            a = (n+a-x)%n;
            b = (n+b-x)%n;
            if(x%2) swap(a,b);
        }else{
            a = (a+n-1)%n;
            b = (b+n+1)%n;
            swap(a,b);
        }
    }
    for(int i=1; i<=n; i++){
        if(i%2) printf("%d ",(a+i-1+n)%n+1);
        else printf("%d ",(b+i-1+n)%n+1);
    }
    return 0;
}
