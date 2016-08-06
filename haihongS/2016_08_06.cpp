#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2e4+100;

string num;
set<string> aha;
int dp[maxn][5];

int main()
{
	while(cin>>num)
	{
		int len=num.length();
		aha.clear();
		memset(dp,0,sizeof(dp));
		dp[len][2]=dp[len][3]=1;
		for(int i=len-2;i>=5;i--)
		{
			if(dp[i+2][3]==1)
				dp[i][2]=1,aha.insert(num.substr(i,2));
			else if(dp[i+2][2]==1 && num.substr(i,2)!=num.substr(i+2,2))
				dp[i][2]=1,aha.insert(num.substr(i,2));

			if(dp[i+3][2]==1)
				dp[i][3]=1,aha.insert(num.substr(i,3));
			else if(dp[i+3][3]==1 && num.substr(i,3)!=num.substr(i+3,3))
				dp[i][3]=1,aha.insert(num.substr(i,3));
		}
		cout<<aha.size()<<endl;
		set<string>::iterator it;
		for(it=aha.begin();it!=aha.end();it++)
			cout<<*it<<endl;
	}

	return 0;
}
