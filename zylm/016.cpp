#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 100005
using namespace std;
int main()
{
	string a1,a2,b1,b2;
	while(cin>>a1>>a2>>b1>>b2)
	{
		int i,j;
		string tmp1,tmp2;
		for(i=0;i<2;i++)if(a1[i]!='X')tmp1+=a1[i];
		for(i=1;i>=0;i--)if(a2[i]!='X')tmp1+=a2[i];
		for(i=0;i<2;i++)if(b1[i]!='X')tmp2+=b1[i];
		for(i=1;i>=0;i--)if(b2[i]!='X')tmp2+=b2[i];
		string res1,res2;
		for(i=0;i<3;i++)
		{
			if(tmp1[i]=='A')
			{
				int cnt=0;
				for(j=i;cnt<3;j++,cnt++)
				 res1+=tmp1[j%3];
			}
			if(tmp2[i]=='A')
			{
				int cnt=0;
				for(j=i;cnt<3;j++,cnt++)
				 res2+=tmp2[j%3];
			}
		}
	//	cout<<res1<<" "<<res2<<endl;
		if(res1==res2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		 
	 } 
}
