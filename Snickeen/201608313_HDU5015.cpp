#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

LL MOD=1e7+7;
LL t,n,m,ans,ff[22];

struct Matrix {
	LL r,c;
	LL a[14][14];
	
}I,f,v;

Matrix MUL(Matrix a,Matrix b){
	LL i,j,k,l;
	Matrix res;
	res.r=a.r;res.c=b.c;
	for(i=0;i<a.r;i++){
		for(j=0;j<b.c;j++){
			res.a[i][j]=0;
			for(k=0;k<a.c;k++)
				res.a[i][j]+=a.a[i][k]*b.a[k][j]%MOD;
			res.a[i][j]%=MOD;
		}
	}
	return res;
}
Matrix MFP(Matrix a,LL b){
	LL i,j,k,l;
	Matrix res = I;
	while(b){
		if(b&1)res=MUL(res,a);
		b>>=1;
		a=MUL(a,a);
	}
	return res;
}

void Matrix_pre(LL a,LL b){
	LL i,j,k,l;
	I.r=a;I.c=b;
	for(i=0;i<a;i++)
		for(j=0;j<b;j++)
			I.a[i][j]=(i==j);
}
void Matrix_get(){
	LL i,j,k,l;
	f.r=f.c=n+2;
	for(i=0;i<f.r;i++){
		for(j=0;j<f.c;j++){
			f.a[i][j]=(i>=j);
		}
		f.a[i][0]=10;
	}
	for(i=0;i<f.r;i++){
		f.a[f.r-1][i]=0;
		f.a[i][f.r-1]=1;
	}
}

void test(Matrix x){
	LL i,j,k,l;
	for(i=0;i<x.r;i++){
		for(j=0;j<x.c;j++){
			cout<<x.a[i][j]<<" "; 
		}
		cout<<endl;
	}cout<<endl;
}

signed main()
{
	LL i,j,k,l;
	Matrix_pre(14,14);
	while(~scanf("%I64d%I64d",&n,&m)){
		I.r=I.c=v.r=v.c=n+2;
		for(i=1;i<=n;i++)scanf("%I64d",&v.a[i][0]);
		v.a[0][0]=233;v.a[n+1][0]=3;
		for(i=1;i<=n;i++)v.a[i][0]+=v.a[i-1][0];
		Matrix_get();
//		test(f);test(v);
		Matrix res=MFP(f,m-1);
		res=MUL(res,v);
		ans=(res.a[n][0]%MOD+MOD)%MOD;
		printf("%I64d\n",ans%MOD);
	}
	return 0;
}
