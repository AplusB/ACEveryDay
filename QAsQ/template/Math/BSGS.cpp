map<int,int> x;

int log_mod(int a,int b,int n){
    int m, v, e=1;
    m=(int)sqrt(n+0.5);
    v=inv(pow_mod(a , m, n), n);
    x.clear();
    x[1]=0;
    for(int i = 1;i < m; i++){
        e=mul_mod(e, a, n);
        if(!x.count[e]) x[e] = i;
    }
    for(int i = 0;i < m; i++){
        if(x.count(b)) return i*m+x[b];
        b=mul_mod(b,v,n);
    }
    return -1;
}

