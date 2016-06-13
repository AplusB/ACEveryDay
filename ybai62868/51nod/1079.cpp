#include <stdio.h>
#define  ULL  unsigned long long

ULL  find( ULL x, int y ) {
        ULL  ans = 0;
        for( int i = 1; i < y; ++i ) if( ( ans = x * i ) % y == 1 ) break;
        return  ans;
}

int main() {
        int  n, i, j, p[10], r[10];
        ULL  mul = 1, k[10], ans = 0;
        scanf( "%d", &n );
        for( i = 0; i < n; ++i ) { scanf( "%d%d", p + i, r + i ); mul *= p[i]; }
        for( i = 0; i < n; ++i ) {
                k[i] = find( mul / p[i], p[i] );
                for( j = 0; j < r[i]; ++j ) ans = ( ans + k[i] ) % mul;
        }
        printf( "%llu\n", ans );
        return 0;
}
