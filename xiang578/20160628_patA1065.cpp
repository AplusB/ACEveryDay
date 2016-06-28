#include<bits/stdc++.h>
using namespace std;

int main()
{
    int _,f=0;
    long long a,b,c;
    scanf("%d",&_);
    for(int __=1;__<=_;__++)
    {
        f=0;
        cin>>a>>b>>c;
        //cout<<a+b<<endl;
        if(a>=0&&b>=0&&c>=0) {if(c-b<a) f=1;}
        else if(a>=0&&b>=0&&c<0) f=1;
        
        else if(a<0&&b>=0) {if(a+b>c) f=1;}
        else if(a>=0&&b<0) {if(a+b>c) f=1;}
        
        else if(a<0&&b<0&&c>=0) f=0;
        else if(a<0&&b<0&&c<0) {if(c-b<a) f=1;}

        printf("Case #%d: ",__);
        if(f) printf("true\n");
        else printf("false\n");
    }
    return 0;
}
