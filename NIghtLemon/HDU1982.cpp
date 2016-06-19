#include<bits/stdc++.h>
using namespace std;
char k[10007];
int l,i;

void Pc()
{
    char q=(k[i]-48);
    if(k[i+1]<='9' && k[i+1]>='0')
        q = q*10+k[++i]-48;
    printf("%c",q+'A'-1);
}

int main()
{
    int T;
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",k);
        l = strlen(k);
        i=0;
        while(i<l){
            if(k[i]=='#') printf(" ");
            else if(k[i]!='-') Pc();
            i++;
        }
        puts("");
    }
    return 0;
}
