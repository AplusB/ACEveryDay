//http://codeforces.com/contest/675/problem/A
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
	std::ios::sync_with_stdio(false);
	LL a,b,c;
	while(cin>>a>>b>>c)
	{
		if((c!=0 && (b-a)%c==0 && (b-a)*c>0)||b==a)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	 
	 } 
}
