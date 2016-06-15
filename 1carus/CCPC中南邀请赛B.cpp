#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#define endl '\n'

using namespace std;

int x,y,z;

int gcd(int a,int b)
{
	if(b == 0)return a;
	else return gcd(b,a % b);
}

void solve(int a,int b,int c)
{
	long long s1 = b * c * ((a + b) + (a + c));
	long long f1 = (a + b + c) * (a + c) * (a + b);
	
	int k = gcd(s1,f1);
	
	cout << s1 / k << "/" << f1 / k;
	
}

int main()
{
	while(scanf("%d %d %d",&x,&y,&z) == 3)
	{
		solve(x,y,z);
		cout << " " ;
		solve(y,x,z);
		cout << " " ;
		solve(z,y,x);
		cout << endl;
	}
	return 0;
} 
