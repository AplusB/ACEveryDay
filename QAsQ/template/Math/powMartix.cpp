const int N=2;
struct martix{
    LL num[N][N];
    void tz(){ memset(num,0,sizeof(num));}
    void to(){
        this->tz();
        for(int i=0;i<N;i++) num[i][i]=1;
    }
};
martix operator * (const martix & A,const martix & B){
    martix C;
    C.tz();
    for(int i=0;i<N;i++) for(int j=0;j<N;j++)
        for(int k=0;k<N;k++)
    ( C.num[i][j]+= A.num[i][k]*B.num[k][j]%MOD ) %=MOD ;
    return C;
}
martix pmod(martix x,LL n)
{
    martix res;
    res.to();
    while(n>0)
    {
        if(n & 1) res=res*x;
        x = x*x;
        n >>= 1;
    }
    return res;
}

