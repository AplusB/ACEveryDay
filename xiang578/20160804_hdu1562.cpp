#include<bits/stdc++.h>
using namespace std;

int main()
{
    int _,a,b,c;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int ok=0;
        for(int i=1000;i<=9999;i++)
        {
            if(i%a==0&&(i+1)%b==0&&(i+2)%c==0)
            {
                ok=1;
                printf("%d\n",i);
                break;
            }
        }
        if(!ok) puts("Impossible");
    }
    return 0;
}
