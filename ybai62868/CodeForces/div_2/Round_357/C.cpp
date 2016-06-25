# include <cstdio>
# include <iostream>
# include <vector>
# include <algorithm>
# include <queue>
# include <string>
using namespace std;
# define inf 99999999
typedef long long LL;
int n;
struct cmp
{
	bool operator () (const int &a,const int &b)
	{
		return a > b;
	}
};

int main(void)
{
	int a,b;
	//char s[15];
	int flag = 0;
	cin>>n;
    priority_queue<int,vector<int>,cmp> qq;
	vector<pair<string,int> > vv;
	while( n-- )
	{
	    int t;
	    string s; cin>>s;
		if(s[0] == 'i')
		{
		   scanf("%d",&t);
		   qq.push(t);
		   vv.push_back({"insert",t});
	    }
	    else
	    {
	    	if(s[0] == 'g')
	    	{
	    		scanf("%d",&t);
	    		if(qq.empty())
	    		{
	    		   vv.push_back({"insert",t});
	    		   qq.push(t);
				   vv.push_back({"getMin",t});
				   continue;
				}
	    		if(t < qq.top())
	    		{
				   qq.push(t);
				   vv.push_back({"insert",t});
				   vv.push_back({"getMin",t});
			    }
			    else
			    {
			      while(!qq.empty())
	    		  {
	    		  	if(qq.top() > t)
	    		  	{
	    		  	    qq.push(t);
				        vv.push_back({"insert",t});
				        vv.push_back({"getMin",t});
				        break;
					}
	    			if(qq.top() == t)
	    			{
					   vv.push_back({"getMin",t});
					   break;
				    }
	    			else
	    			{
	    				vv.push_back({"removeMin",inf});
	    				qq.pop();
					}
				  }

				  	if(qq.empty())
				  	{
				  		vv.push_back({"insert",t});
				  		qq.push(t);
				  		vv.push_back({"getMin",t});
					}
				}
			}
			else
			{
				if(qq.empty())
				{
				  		vv.push_back({"insert",0});
				  		vv.push_back({"removeMin",inf});
				  		continue;
				}
				qq.pop();
				vv.push_back({"removeMin",inf});
			}
		}
	}

    int len = vv.size();
    cout<<len<<endl;
	for( int i = 0;i < len;i++)
	{
		if(vv[i].second == inf)
		  cout<<vv[i].first<<endl;
		else
		 cout<<vv[i].first<<" "<<vv[i].second<<endl;
	}
	return 0;
}
