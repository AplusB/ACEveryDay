#include<bits/stdc++.h>
using namespace std;
int a[100007];
int n,m;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int i;
        for(i=0;i<n;i++){
            if(a[i]>m) break;
            m-= a[i];    
        }
        printf("%d\n",i);
    }
    return 0;
}
