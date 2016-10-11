#define LL long long 
LL mult_mod(LL a,LL b,LL c){
    a %= c,b %= c;
    LL ret = 0,tmp = a;
    while(b){
        if(b & 1){
            ret += tmp;
            if(ret > c) ret -= c;
        }
        tmp <<= 1;
        if(tmp > c) tmp -= c;
        b >>= 1;
    }
    return ret;
}
