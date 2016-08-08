const int maxn = 10,maxm = 10;
struct Edge{
    #define foreach(i,st,Edg) for(int i = Edg.head[st];i != -1;i = Edg.node[i].nex)
    struct Node{
        int nex,to;
        Node(int nex=0,int to=0):nex(nex),to(to){};
    };
    Node node[maxm];
    int head[maxn],top;
    void init(){
        memset(head,-1,sizeof(head));
        top = 0;
    }
    void Link(int st,int ed){
        node[top] = Node(head[st],ed);
        head[st] = top++;
    }
};
