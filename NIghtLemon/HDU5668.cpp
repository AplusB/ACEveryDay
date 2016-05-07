#include<bits/stdc++.h>
/**周五十节课，两份实验报告 
  *很惭愧，来不及了，刷了道水题来凑数 
  *5月7日补两道以做弥补 
  *  by NightLemon
  */ 
using namespace std;
typedef long long ll;
int main()
{
	int T;
	ll n;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==3 ||(n>4) && (n%4!=2)) cout<<"True"<<endl;
		else cout<<"False"<<endl;
	}
	return 0 ;
}
