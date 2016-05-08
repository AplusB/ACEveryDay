#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=1000010;
const int MAX=151;
const int mod=100000000;
const int MOD1=100000007;
const int MOD2=100000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=1000000000;
const ll INF=10000000010;
typedef double db;
typedef unsigned long long ull;
char s[N],c[N],d[N];
int les,lec,x[10],y[10],z[10];
int check(int w) {
    int i,k=0,g=0,W=w;
    memset(z,0,sizeof(z));
    while (w) { g++;z[w%10]++;w/=10; }
    if (les!=W+g) return 0;
    for (i=0;i<10;i++)
    if (x[i]<y[i]+z[i]) return 0;
    for (i=1;i<10;i++)
    if (x[i]>y[i]+z[i]) k++;
    if (!k&&c[0]=='0') return 0;
    return 1;
}
int compare(int lec,int led) {
    char C,D;
    for (int i=0;i<lec+led;i++) {
        if (i<lec) C=c[i];
        else C=d[i-lec];
        if (i<led) D=d[i];
        else D=c[i-led];
        if (C<D) return 1;
        if (C>D) return 0;
    }
    return 1;
}
void print_out(int w) {
    int i,j,k=0,W=w,bo=0;
    for (i=0;i<10;i++) x[i]-=y[i];
    while (w) { x[w%10]--;w/=10; }
    for (i=1;i<10;i++)
        for (j=1;j<=x[i];j++) d[k++]=i+'0';
    for (i=k-1;i>0;i--) d[i+x[0]]=d[i];
    if (k) for (i=1;i<=x[0];i++) d[i]='0';
    else for (i=0;i<x[0];i++) d[i]='0';
    k+=x[0];d[k]='\0';
    if (k==0) { printf("%s\n", c);return ; }
    if (d[0]=='0'||(c[0]!='0'&&compare(lec,k))) {
        printf("%s", c);
        for (i=0;i<10;i++)
            for (j=1;j<=x[i];j++) printf("%c", i+'0');
        printf("\n");
    } else {
        printf("%c", d[0]);
        for (i=1;i<lec;i++)
        if (c[i]!=c[i-1]) {
            if (c[i]>c[i-1]) bo=1;break ;
        }
        if (bo) {
            for (i=1;i<k;i++)
            if (d[i]>c[0]) break ;
            else printf("%c", d[i]);
            printf("%s", c);
            for (j=i;j<k;j++) printf("%c", d[j]);
            printf("\n");
        } else {
            for (i=1;i<k;i++)
            if (d[i]>=c[0]) break ;
            else printf("%c", d[i]);
            printf("%s", c);
            for (j=i;j<k;j++) printf("%c", d[j]);
            printf("\n");
        }
    }
}
int main()
{
    int i;
    scanf("%s%s", s, c);
    les=strlen(s);lec=strlen(c);
    for (i=0;i<les;i++) x[s[i]-'0']++;
    for (i=0;i<lec;i++) y[c[i]-'0']++;
    if (les==2&&lec==1&&x[0]==1&&x[1]==1&&y[0]==1) {
        printf("0\n");return 0;
    }
    for (i=1;i<=les;i++)
    if (check(i)) {
        print_out(i);break ;
    }
    return 0;
}
