#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int main()
{
	scanf("%d %d",&n,&m);
	int l=1,r=n;
	for(int i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        if(x>y) swap(x,y);
        l=max(l,x);
        r=min(r,y);
    }
    if(l>r) printf("0");
    else printf("%d",r-l);
}
