http://codeforces.com/contest/8/problem/A
cf原题
#include <cstdio>  
#include <string>  
#include <cstring>   
#include <iostream>  
using namespace std;  
  
int main()  
{  
    string s,a,b;  
    cin>>s>>a>>b;  
    string sr="";  
    for(int i=s.length()-1;i>=0;i--) sr+=s[i];  
    int pa=s.find(a,0),pb=s.find(b,pa+a.length());  
    int pra=sr.find(a,0),prb=sr.find(b,pra+a.length());  
    //这里的 +xx.length()是为了不重叠哦~ find后的参数是(要找的子串，从第几个位置开始找)   
    bool f1=(pa==string::npos || pb==string::npos),f2=(pra==string::npos || prb==string::npos);  
    if(f1 && f2) cout<<"fantasy";  
    else if(!f1 && f2) cout<<"forward";  
    else if(f1 && !f2) cout<<"backward";  
    else cout<<"both";  
    return 0;  
} 
