#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 121345;

LL rex[maxn];
LL rey[maxn];

double caldis(LL x1,LL y1,LL x2,LL y2){
    LL x = x1 - x2;
    LL y = y1-y2;
    LL su = x * x + y * y;
    return sqrt((double)su);
}

double caldis(int id,LL x,LL y){
    return caldis(rex[id],rey[id],x,y);
}

void can(LL x,LL y,LL tx,LL ty,int n,int &id,int &bd,double &dif1,double &dif2){
    bd = -1;
    dif1 = caldis(0,x,y) - caldis(0,tx,ty);
    id = 0;
    for(int i=1;i<n;i++){
        double tem = caldis(i,x,y) - caldis(i,tx,ty);
        if(tem < dif1){
            dif1 = tem;
            id = i;
        }
    }
    if(n==1)
        return;
    if(id == 0){
        bd = 1;
    }
    else{
        bd = 0;
    }
    dif2 = caldis(bd,x,y) - caldis(bd,tx,ty);
     for(int i=0;i<n;i++){
        if(i == id) continue;
        double tem = caldis(i,x,y) - caldis(i,tx,ty);
        if(tem < dif2){
            dif2 = tem;
            bd = i;
        }
    }
}

int main(){
    LL ax,ay,bx,by,tx,ty;
    cin>>ax>>ay>>bx>>by>>tx>>ty;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>rex[i]>>rey[i];
    double all = 0;
    for(int i=0;i<n;i++)
        all += 2 * caldis(rex[i],rey[i],tx,ty);
    double a1,a2,b1,b2;
    int i1,i2,j1,j2;
    can(ax,ay,tx,ty,n,i1,i2,a1,a2);
    can(bx,by,tx,ty,n,j1,j2,b1,b2);
    int v[2],u[2];
    double ans = all + a1;
    ans = min(ans,all + b1);
    v[0] = i1,v[1] = i2;
    u[0] = j1,u[1] = j2;
    double dv[2],du[2];
    dv[0] = a1,dv[1] = a2;
    du[0] = b1,du[1] = b2;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(u[i] != v[j] && u[i] != -1 && v[j]!=-1){
                ans = min(ans,all + dv[j] + du[i]);
            }
        }
    }
    printf("%.10f\n",ans);
    return 0;
}
