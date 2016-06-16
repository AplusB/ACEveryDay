#include<iostream>
#include <cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=405;
set<int> st;
set<int>::iterator it;
vector<int> ans;
vector<int>::iterator it1;
int main()
{
        int n,x,y;
    bool flag=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&x);
            st.insert(x);
    }
    scanf("%d %d",&x,&y);
    it=st.begin();
    printf("%d",*it++);
    for(;it!=st.end();it++)
    {
            printf(" %d",*it);
            if(*it>x && *it<y) ans.push_back(*it);
    }
    printf("\n");
    if(ans.size()==0) printf("NOT FOUND");
    else
    {
            it1=ans.begin();
    printf("%d",*it1++);
    for(;it1!=ans.end();it1++)
    {
        printf(" %d",*it1);
    }
    }
    printf("\n");
        scanf("%d",&y);
    st.erase(y);
        it=st.begin();
    printf("%d",*it++);
    for(;it!=st.end();it++)
    {
            printf(" %d",*it);
    }
    printf("\n");
    scanf("%d",&x);
    st.insert(x);
    it=st.begin();
    printf("%d",*it++);
    for(;it!=st.end();it++)
    {
            printf(" %d",*it);
    }
    printf("\n");
    return 0;
}

