#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[500005],op[500005];
list<int> lst;
int main()
{
     int n,m,p;
     scanf("%d %d %d",&n,&m,&p);
     scanf("%s",a);
     scanf("%s",op);
     for (int i = 0; i < n; ++i)
		lst.push_back(i);
	 auto it = lst.begin();
	 while(--p)
        ++it;
     for(int i=0;i<m;i++)
     {
         if(op[i]=='L')
            --it;
         else if(op[i]=='R')
            ++it;
         else if(a[*it]=='(')
         {
             int cnt=1;
             it=lst.erase(it);
             while(cnt)
             {
                 cnt+=(a[*it]=='(')*2-1;
                 it=lst.erase(it);
             }
         }
        else
		{
			int cnt = 1;
			it = lst.erase(it);
			while (cnt)
			{
				cnt += (a[*--it] == ')') * 2 - 1;
				it = lst.erase(it);
			}
		}
		if(it==lst.end()) --it;
     }
     for(auto i : lst)
        printf("%c",a[i]);
     printf("\n");
     return 0;
}
/*
8 4 5
(())()()
RDLD
*/
