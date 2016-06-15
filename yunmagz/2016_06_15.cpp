//CF#357 Div. 2
//A
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    string s;
    cin>>n;
    int flag=0;
    for(int i=0;i<n;i++){
        cin>>s>>a>>b;
        if(a>=2400){
            if(b>a)
                flag=1;
        }
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}
//B
#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
    LL n;
    cin>>n;
    int flag=0;
    for(int i=0;i*1234567ll<=n;i++){
        for(int j=0;i*1234567ll+j*123456ll<=n;j++){
            if((n-i*1234567ll-j*123456ll)%1234==0)
                flag=1;
        }
    }
    if(flag) puts("YES");
    else puts("NO");
    return 0;
}
//C
#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> >q;
char s[100010][10];
int a[100010];
int main(){
    string ins="insert",get="getMin",rem="removeMin";
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        if(s[i][0]=='i'){
            scanf("%d",&a[i]);
            ans++;
            q.push(a[i]);
        }
        else if(s[i][0]=='g'){
            scanf("%d",&a[i]);
            while(!q.empty() &&q.top()<a[i]){
                ans++;
                q.pop();
            }
            if(q.empty()){
                ans+=2;
                q.push(a[i]);
            }
            else if(q.top()>a[i]){
                ans+=2;
                q.push(a[i]);
            }
            else {
                ans++;
            }
        }
        else {
            if(q.empty()){
                ans+=2;
            }
            else {
                ans++;
                q.pop();
            }
        }
    }
    while(!q.empty()){
        q.pop();
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++){
        if(s[i][0]=='i'){
            printf("insert %d\n",a[i]);
            q.push(a[i]);
        }
        else if(s[i][0]=='g'){
            while(!q.empty() &&q.top()<a[i]){
                printf("removeMin\n");
                q.pop();
            }
            if(q.empty()){
                printf("insert %d\n",a[i]);
                printf("getMin %d\n",a[i]);
                q.push(a[i]);
            }
            else if(q.top()>a[i]){
                printf("insert %d\n",a[i]);
                printf("getMin %d\n",a[i]);
                q.push(a[i]);
            }
            else {
                printf("getMin %d\n",a[i]);
            }
        }
        else {
            if(q.empty()){
                printf("insert 1\n");
                printf("removeMin\n");
            }
            else {
                printf("removeMin\n");
                q.pop();
            }
        }
    }
    return 0;
}
