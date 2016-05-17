int prime[plen+1];
int mobius[plen+1];
int getPrime(){
    memset(prime,0,sizeof(prime));
    memset(mobius,0,sizeof(mobius));
    mobius[1]=0;
    for(int i = 2; i<=plen; i++){
        if(!prime[i]) prime[++prime[0]] = i , mobius[i] = -1;
        for(int j = 1; j <= prime[0] && prime[j] <=plen / i; j++){
            prime[prime[j]*i] = 1;
            if (i % prime[j] == 0) break;
            else mobius[i*prime[j]] = -mobius[i];
        }
    }
    return prime[0];
}

