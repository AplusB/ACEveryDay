# include <cstdio>
# include <iostream>
# include <cstring>
# include <string>
# define MAX 112345
using namespace std;
# define inf 99999999
int main(void)
{
	int n,l,v1,v2,k;
	cin>>n>>l>>v1>>v2>>k;
	double times = n/k+(n%k!=0);
	double temp = times / (v2 - v1) + (times - 1) / (v2 + v1);
	double res = temp * l / (1 + temp * v1); 
	printf("%.10lf\n",res);
	return 0;
}
