//CF#352 div2
//A
#include <bits/stdc++.h>
using namespace std;
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int n;
    char a[110];
    string s="";
    for(int i=1;;i++){
    stringstream aa;
    string d;
        aa<<i;
        aa>>d;
        if(s.size()>=1000) break;
        s.append(d);
//        cout<<s<<endl;
    }
    cin>>n;
    cout<<s.at(n-1)<<endl;
    return 0;
}
//B
#include <bits/stdc++.h>
using namespace std;
int v[110];
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int n;
    string s;
    cin>>n;
    cin>>s;
    if(n>26) puts("-1");
    else {
        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[s[i]-'a']) cnt++;
            v[s[i]-'a']++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
//C
#include <bits/stdc++.h>
using namespace std;
double x[100010],y[100010],da[100010],db[100010];
double dis(double x,double y,double xx,double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
    int n;
    double ax,ay,bx,by,tx,ty;
    cin>>ax>>ay>>bx>>by>>tx>>ty;
    cin>>n;
    double sum=0;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
        double a=dis(x[i],y[i],tx,ty);
        sum+=a;
        da[i]=a-dis(x[i],y[i],ax,ay);
        db[i]=a-dis(x[i],y[i],bx,by);
    }
    sum*=2;
    double mxa=-1e18,mxb=-1e18;
    int ida,idb;
    for(int i=0;i<n;i++){
        if(da[i]>mxa)ida=i,mxa=da[i];
        if(db[i]>mxb)idb=i,mxb=db[i];
    }
    double ans=max(mxa,mxb);
    for(int i=0;i<n;i++){
        if(i!=ida) ans=max(ans,mxa+db[i]);
        if(i!=idb) ans=max(ans,mxb+da[i]);
    }
    cout<<setprecision(20)<<sum-ans<<endl;
    return 0;
}
