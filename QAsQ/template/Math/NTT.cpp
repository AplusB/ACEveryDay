const LL P=31525197391593473,r=3;

void mod_add(LL &a,LL b){
    if((a+=b)>=P)a-=P;
}
void mod_minus(LL &a,LL b){
    if((a-=b)<0)a+=P;
}
LL mul(LL x,LL y,LL z){
	return (x*y - (LL)(x/(long double)z*y+1e-3)*z+z)%z;
}

LL fast_mod_pow(LL a,LL b){
    LL res=1;
    for(;b;b>>=1,a=mul(a,a,P))
        if(b&1)res=mul(res,a,P);
    return res;
}

inline LL calc_inv(LL x){
    return fast_mod_pow(x,P-2);
}

const LL N=(1<<18)+5;
LL rev[N],A[N],B[N],C[N];

void DFT(LL *arr,LL n,bool flag){
    rep(i,0,n)if(i<rev[i])swap(arr[i],arr[rev[i]]);
    for(LL m=2;m<=n;m<<=1){
        LL g=fast_mod_pow(r,(P-1)/m);
        if(flag)g=calc_inv(g);
        for(LL i=0;i<n;i+=m){
            LL cur=1;
            rep(j,0,m>>1){
                LL x=arr[i+j],y=mul(cur,arr[i+j+(m>>1)],P);
                mod_add(arr[i+j]=x,y);
                mod_minus(arr[i+j+(m>>1)]=x,y);
                cur=mul(cur,g,P);
            }
        }
    }
}
void NTT(LL n,LL m){
    LL _n,S;
    for(_n=1,S=0;_n<n+m;_n<<=1,++S);
    rep(i,1,_n)rev[i]=(rev[i>>1]>>1)|((i&1)<<S-1);
    rep(i,n,_n)A[i]=0;
    rep(i,m,_n)B[i]=0;
    DFT(A,_n,false);
    DFT(B,_n,false);
    rep(i,0,_n)C[i]=mul(A[i],B[i],P);
    DFT(C,_n,true);
    LL inv=calc_inv(_n);
    rep(i,0,_n)C[i]=mul(C[i],inv,P);
}
