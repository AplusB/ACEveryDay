#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int gcd (int x, int y) 
{
    if(x * y == 0) return x + y;
	else return gcd(y, x % y);    
}

int main()
{
    int s,n,m;
    while (scanf("%d%d%d", &s, &n, &m) != EOF && s && n && m) {
        if ((s /= gcd(n,m)) & 1) puts("NO");
        else printf("%d\n", s - 1);
        //cout << s << endl;
    }
    
    return 0;
}