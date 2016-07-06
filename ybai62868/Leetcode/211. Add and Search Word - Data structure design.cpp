class TrieNode
{
    public:
    map<char,TrieNode*>M;
    bool isWord;
    TrieNode()
    {
        isWord = false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary()
    {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* T = root;
        for(int i=0; i<word.size(); i++)
        {
            if(T->M.find(word[i]) == T->M.end())
            {
                T->M[word[i]] = new TrieNode();
            }
            T = T->M[word[i]];
        }
        T->isWord = true;
    }

    bool search(string word){
        return search(word,root);
    }
    bool search(string word, TrieNode *T) {
        for(int i=0; i<word.size(); i++)
        {
            if(word[i] == '.')
            {
                string sub = word.substr(i+1);
                for(auto it = T->M.begin(); it!=T->M.end(); ++it)
                {
                    if(search(sub, it->second))return true;
                }
                return false;
            }
            else if(T->M.find(word[i]) == T->M.end())
            {
                return false;
            }
            T = T->M[word[i]];
        }
        return(T->isWord);
    }
};
