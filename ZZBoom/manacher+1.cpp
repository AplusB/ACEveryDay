//hdoj3294


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn =200000+50;
char s[maxn<<1];
int p[maxn<<1];
int mxx,iid;
void manacher()
{
    mxx=-1;
    int len=strlen(s);
    for(int i=len;i>=0;i--)
    {
        s[i+i+2] = s[i];
        s[i+i+1] = '#';
    }
    s[0] = '*';
    int id,mx=0;
    for(int i=1;i<len+len+2;i++)
    {
        if(mx>1) p[i] = min(p[2*id-i],mx-i);
        if(p[i]==0) p[i]=1;
        while(s[i-p[i]]==s[i+p[i]])p[i]++;
        if(i+p[i]>mx)
        {
            mx=i+p[i];
            id=i;
        }
        if(p[i]-1>mxx)
        {
            mxx=p[i]-1;
            iid=i;
        }
    }
}

int main()
{
    char c;
    while(~scanf("%c%s",&c,s))
    {
        getchar();
        int k = c-'a';
        int len=strlen(s);

        for(int i=0;i<len;i++)
        {
            s[i]-=k;
            if(s[i]<'a')
                s[i]+=('z'-'a'+1);
        }
        manacher();
        if(mxx==1)
         printf("No solution!\n");
        else
        {
            printf("%d %d\n",(iid-mxx+1)/2-1,(iid+mxx-1)/2-1);
            for(int i=(iid-mxx+1);i<=(iid+mxx-1);i++)
            if(s[i]!='#'&&s[i]!='*')
            printf("%c",s[i]);
            printf("\n");
        }
    }
}
