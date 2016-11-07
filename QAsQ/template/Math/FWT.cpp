<TeX> $C_i=\sum_{j \oplus k=i}A_j*B_k$ </TeX>
void fwt (LL a[] , int n ,bool on) {
    for ( int d = 1 ; d < n ; d <<= 1 ) {
        for ( int k = d << 1 , i = 0 ; i < n ; i += k ) {
            for ( int j = 0 ; j < d ; ++ j ) {
                LL x = a[i + j] , y = a[i + j + d] ;
                if(on){
                //xor
                    a[i + j] = ( x + y ) % mod ;
                    a[i + j + d] = ( x - y + mod ) % mod ;
                //and
                    a[i + j] = ( x + y ) % mod;
                    a[i + j + d];
                //or
                    a[i + j];
                    a[i + j + d] = ( y + x ) % mod ;
                }
                else{
                //xor
                    a[i + j] = ( x + y ) * rev_2% mod ;
                    a[i + j + d] = ( x - y + mod ) * rev_2% mod ;
                //and
                    a[i + j] = ( x - y + mod ) % mod;
                    a[i + j + d];
                //or
                    a[i + j];
                    a[i + j + d] = ( y - x + mod ) % mod ;
                }
            }
        }
    }
}
