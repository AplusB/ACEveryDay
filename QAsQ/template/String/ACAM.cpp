const int maxn = 112345,maxLen = 130;

int toid(char c){ return c; }
queue<int> Q;

struct acam{
    int nex[maxn][maxLen],fail[maxn];
    int cnt[maxn];
    int _cnt,root;
    int newNode(){
        memset(nex[_cnt],fail[_cnt] = -1,sizeof(nex[_cnt]));
        cnt[_cnt] = 0;
        return _cnt++;
    }
    void init(){
        _cnt = 0;
        root = newNode();
    }
    void insert(char *arr,int id){
        int st = root;
        for(int i=0;arr[i];i++){
            int & stx = nex[st][toid(arr[i])];
            if(stx == -1) stx = newNode();
            st = stx;
        }
        cnt[st]++;
        // update cnt
    }
    void build(){
        while(Q.empty()==false) Q.pop();
        fail[root] = root;
        int st;
        for(int i=0;i<maxLen;i++){
            if((st = nex[root][i]) != -1){
                fail[st] = root;
                Q.push(st);
            }
            else nex[root][i] = root;
        }
        while(Q.empty()==false){
            st = Q.front(),Q.pop();
            for(int i=0;i<maxLen;i++){
                if(nex[st][i] != -1){
                    int fst = fail[st],son = nex[st][i];
                    while(fst != root && nex[fst][i] == -1)
                        fst = fail[fst];
                    fail[son] = nex[fst][i] == -1 ? root : nex[fst][i];
                    Q.push(son);
                }
                else{
                    nex[st][i] = nex[fail[st]][i];
                }
            }
        };
    }
    int cal(char *arr){
        int st = root;
        for(int i=0;arr[i];i++){
            st = nex[st][toid(arr[i])];
            int tem = st;
            while(tem != root){
                // cal something
                tem = fail[tem];
            }
        }
        // return something
    }
}acam;

