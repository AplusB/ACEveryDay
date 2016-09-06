/*
https://www.hackerrank.com/challenges/vector-sort
*/
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<complex>
using namespace std;
typedef long long LL;
typedef double db;
#define repu(i,a,b) for(i=a;i<=b;i++)
const int maxn = 2000+10;
const LL MOD=(1ll<<31);
LL t,n,m,ans,s,p,q;

vector<LL> v;

int main()
{
	LL i,j,k,l,r;
	cin>>n;
	repu(i,1,n)cin>>m,v.push_back(m);
	sort(v.begin(),v.end());
	for(auto x:v)cout<<x<<" "; 
	return 0;
}
