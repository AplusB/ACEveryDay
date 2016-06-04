//http://codeforces.com/contest/672/problem/B
//关掉输入同步会出错，陷入死循环

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
//	read;
//	std::ios::sync_with_stdio(false);
	int n;
	while(~scanf("%d",&n))
	{
		string str;
		cin>>str;
		int i,cnt=0,tmp=0;
		map<char,char> mp;
		for(i=0;i<str.length();i++)
		{
			if(mp[str[i]]==0)mp[str[i]]=1,tmp++;
			else cnt++;
		}
		if(cnt+tmp<=26)cout<<cnt<<endl;
		else cout<<"-1"<<endl;
	 } 
}
