//hdu3939 - Sticks and Right Triangle
#include <bits/stdc++.h>
using namespace std;  
typedef long long LL;  
  
const int N=1000005;  
  
int p[N],phi[N];  
bool prime[N];  
int check[35];  
int k,num;  
LL ans,L;  
  
void isprime()  
{  
    k=0;  
    int i,j;  
    memset(prime,true,sizeof(prime));  
    for(i=2;i<N;i++)  
    {  
        if(prime[i])  
        {  
            p[k++]=i;  
            for(j=i+i;j<N;j+=i)  
            {  
                prime[j]=false;  
            }  
        }  
    }  
}  
  
void Init_phi()  
{  
    int i,j;  
    for(i=1;i<N;i++)  phi[i]=i;  
    for(i=2;i<N;i+=2) phi[i]>>=1;  
    for(i=3;i<N;i+=2)  
    {  
        if(phi[i]==i)  
        {  
            for(j=i;j<N;j+=i)  
            {  
                phi[j]=phi[j]-phi[j]/i;  
            }  
        }  
    }  
}  
  
void prime_check(int n)  
{  
    num=0;  
    if(prime[n])  
    {  
        check[num++]=n;  
        return;  
    }  
    for(int i=0;i<k&&n>1;i++)  
    {  
        if(n%p[i]==0)  
        {  
            check[num++]=p[i];  
            while(n%p[i]==0) n/=p[i];  
            if(n>1&&prime[n])  
            {  
                check[num++]=n;  
                return;  
            }  
        }  
    }  
}  
  
void dfs(int k,int r,int s,int n)  
{  
    if(k==num)  
    {  
        if(r&1) ans-=n/s;  
        else    ans+=n/s;  
        return;  
    }  
    dfs(k+1,r,s,n);  
    dfs(k+1,r+1,s*check[k],n);  
}  
  
int main()  
{  
    int T;  
    isprime();  
    Init_phi();  
    cin>>T;  
    while(T--)  
    {  
        ans=0;  
        cin>>L;  
        int m=(int)sqrt(1.0*L);  
        for(int i=m;i>0;i--)  
        {  
            int p=(int)sqrt(L-(LL)i*i);  
            if(i&1)  
            {  
                prime_check(i);  
                if(i<=p) dfs(0,0,1,i>>1);  
                else     dfs(0,0,1,p>>1);  
            }  
            else  
            {  
                if(i<=p) ans+=phi[i];  
                else  
                {  
                    prime_check(i);  
                    dfs(0,0,1,p);  
                }  
            }  
        }  
        cout<<ans<<endl;  
    }  
    return 0;  
}  
