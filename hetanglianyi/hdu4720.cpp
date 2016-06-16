#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int cases,ca=0;  cin >> cases;
    while( ++ca <= cases ){
        double x[6], y[6], r, t;
        for( int i=1; i<=4; i++ )
            cin >> x[i] >> y[i];

        if( (y[2]-y[1])*(x[3]-x[1]) == (y[3]-y[1])*(x[2]-x[1]) ){
            int m=1, n=1;
            for( int i=2; i<=3; i++ ){
                m = y[i]>y[m] ? i : m;
                n = y[i]<y[n] ? i : n;
            }
            x[0] = ( x[m] + x[n] ) / 2;
            y[0] = ( y[m] + y[n] ) / 2;

            r = (x[m]-x[0])*(x[m]- x[0]) + (y[m]-y[0])*(y[m]-y[0]);
        }

        double a = (x[1]-x[2])*(x[1]-x[2]) + (y[1]-y[2])*(y[1]-y[2]);
        double b = (x[1]-x[3])*(x[1]-x[3]) + (y[1]-y[3])*(y[1]-y[3]);
        double c = (x[3]-x[2])*(x[3]-x[2]) + (y[3]-y[2])*(y[3]-y[2]);

        if( a+b>c && b+c>a && c+a>b ){
            t = (x[2]-x[1])*(y[1]-y[3]) - (x[3]-x[1])*(y[1]-y[2]);
            x[0] = y[1]*( y[3]-y[2] ) + (x[1]*x[1]-x[3]*x[3])*(y[1]-y[2]) - (x[1]*x[1]-x[2]*x[2])*(y[1]-y[3]);
            x[0] = x[0] / t / 2;

            int m=1, n=2;
            if( y[1] == y[2] )  n=3;
            double k = (x[n]-x[m]) / (y[m]-y[n]);
            double f = (y[m]+y[n])/2 - k * (x[m]+x[n])/2;
            y[0] = k*x[0] + f;

            r = (x[1]-x[0])*(x[1]- x[0]) + (y[1]-y[0])*(y[1]-y[0]);
        }

        else{
            int m, n;
            if( a+b<=c )  m=2, n=3;
            if( b+c<=a )  m=1, n=2;
            if( c+a<=b )  m=3, n=1;

            x[0] = ( x[m] + x[n] ) / 2;
            y[0] = ( y[m] + y[n] ) / 2;
            r = (x[m]-x[0])*(x[m]- x[0]) + (y[m]-y[0])*(y[m]-y[0]);
        }

        if( (x[4]-x[0])*(x[4]-x[0]) + (y[4]-y[0])*(y[4]-y[0]) - r <= 10e-8 )
            cout << "Case #" << ca << ": Danger" << endl;
        else cout << "Case #" << ca << ": Safe" << endl;
    }
}
