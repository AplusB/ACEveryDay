#include<iostream>
#include<math.h>
using namespace std;



unsigned comp(unsigned n, unsigned m)
{
    unsigned a = m + n;
    unsigned b = (m < n ? m : n);
    double cnm = 1.0;
    while(b > 0)
        cnm *= (double)(a--) / (double)(b--);

    cnm += 0.5;  
    return (unsigned)cnm;
}

int main(void)
{
    unsigned m, n;
    while(true)
    {
        cin >> m >> n;
        if(!m && !n)
            break;

        cout << comp(n, m) << endl;
    }
    return 0;
}
