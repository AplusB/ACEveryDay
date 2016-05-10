#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define ll long long  
#define pr(str) printf("%s\n",str)

using namespace std;

const int MAXN = 10005;
const int HASH = 10007;
const int SEED = 123;

int S[MAXN];
char pre[MAXN],suf[MAXN],str[MAXN];

struct HASHMAP  
{  
    int head[HASH],next[MAXN],sz;  
    unsigned ll state[MAXN];  
  
    void init()  
    {  
        sz = 0;  
        memset(head,-1,sizeof(head));  
    }  
  
    int Insert(unsigned ll val)  
    {  
        //cout<<val<<endl;  
        int h = val%HASH;  
        for(int i = head[h]; ~i; i = next[i])  
            if(val == state[i])  
                return 0;  
  
        state[sz] = val;  
        next[sz] = head[h];  
        head[h] = sz++;  
        return 1;  
    }  
}H;

int Count(char *st,int len)  
{  
    for(int i = 1; i <= len; ++i) S[i] = S[i-1]*SEED+st[i-1];  
    return H.Insert(S[len]);  
}  

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		H.init();
		int ans = 1;
		scanf("%s",str);
		
		int i,len = strlen(str);
		
		Count(str,len);
		for(i = 1;str[i];i++)
		{
			strncpy(pre,str,i); //warning : str[i] does not copy
			pre[i] ='\0';
			strcpy(suf,str + i);
			//cout << "*" << '\n';
			//pr(pre);pr(suf);
			//cout << "*" << '\n';
			
			//3412
			strcpy(suf + len - i,pre);
			suf[len] = '\0';
			ans += Count(suf,len);
			//pr(suf);
			
			//3421
			reverse(suf + len - i,suf + len);
			ans += Count(suf,len);
			
			//4321
			reverse(suf,suf + len - i);
			ans += Count(suf,len);
			//pr(suf);
			
			//4312
			reverse(suf + len - i,suf + len);
			ans += Count(suf,len);
			//pr(suf);
			
			//1243
			strncpy(pre + i,suf,len - i);
			pre[len] = '\0';
			ans += Count(pre,len);
			//pr(pre);
			
			//2143
			reverse(pre,pre + i);
			ans += Count(pre,len);
			//pr(pre);
			
			//2134
			reverse(pre + i,pre + len);
			ans += Count(pre,len);
			//pr(pre);
		}
		
		cout << ans << endl; 
	}
	return 0;
}
