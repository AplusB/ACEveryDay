#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

using namespace std;

long long x,y,z,a,b;
long long n,k;

bool judge(long long x,long long y,long long z)
{
	if(x < 0 || y < 0 || z < 0)return false;
	if(x + y + z != k)return false;
	
	long long mmax = max(x,max(y,z));

	long long temp  = 0;
	temp += mmax - x;
	temp += mmax - y;
	temp += mmax - z; 
	
	if(temp > n - k || (n - k - temp) % 3)return false;
	else 
	{
		//cout << x << " " << y << " " << z << endl;
		return true;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d %I64d %I64d %I64d",&n,&k,&a,&b);
		
		z = (k - 2 * b - a) / 3;
		if(judge(z + a + b,z + b,z))
		{
			cout << "yes" << endl;
			continue;
		}
		z = (k - 2*b + a) / 3;
		if(judge(z + b - a,z + b,z))
		{
			cout << "yes" << endl;
			continue;
		}
		z = (k + a + 2 * b) / 3;
		if(judge(z - b - a,z - b,z))
		{
			cout << "yes" << endl;
			continue;
		}
		z = (k - a + 2 * b) / 3;
		if(judge(z - b + a,z - b,z))
		{
			cout << "yes" << endl;
			continue;
		}
		cout << "no" << endl;
	} 
	return 0;
} 
