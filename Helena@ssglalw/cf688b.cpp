#include <cstdio>
using namespace std;
const int MAX_N = 100005;

char n[MAX_N];

int main()
{
	scanf("%s", n);
	int len = 0;
	while(n[len] != '\0') len++;
	printf("%s", n);
	for(int i=len-1; i>=0; i--)
		printf("%c", n[i]);
	printf("\n");
	return 0;
}
