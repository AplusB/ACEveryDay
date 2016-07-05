#include<bits/stdc++.h>
using namespace std;

struct TT{
    char a[22];
    int n;
};TT t[2];

int main()
{
    char str[22];
    int n,m,i,j,k,l,res;
    scanf("%d",&n);
    scanf("%s",t[0].a);t[0].n=1;k=1;
    while(--n){
        scanf("%s",str);l=0;
        for(i=0;i<k;i++){
            if(strcmp(str,t[i].a)==0){
                t[i].n++;
                l=1;
            }
        }
        if(!l){
            strcpy(t[i].a,str);
            t[i].n++;
        }
    }
    t[0].n>t[1].n?k=0:k=1;
    puts(t[k].a);
    return 0;
}
