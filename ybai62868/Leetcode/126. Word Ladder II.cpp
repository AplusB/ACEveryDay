class Solution 
{
private:
    unordered_map<string, unordered_set<string>> store;

public:    
    vector<vector<string>> createSequences(string beginWord, string endWord)
    {
        vector<vector<string>> result;
        if(beginWord == endWord)
        {
            vector<string> row;
            row.push_back(beginWord);
            result.push_back(row);
            return result;
        }
        for(auto it: store[endWord])
        {
            vector<vector<string>> res = createSequences(beginWord, it);
            for(int i = 0; i < res.size(); i++)
            {
                res[i].push_back(endWord);
                result.push_back(res[i]);
            }
        }
        return result;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) 
    {
        queue<string> q;
        bool endFlag = false;
        int sz = 0, wsz = beginWord.size();
        string curr, temp;
        q.push(beginWord);
        wordList.erase(beginWord);
        unordered_set<string> current;
        while(!q.empty() && !endFlag)
        {
            sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                curr = q.front();
                q.pop();
                for(int j = 0; j < wsz; j++)
                {
                    for(char k = 'a'; k <= 'z'; k++)
                    {
                        temp = curr;
                        if(temp[j] == k)
                            continue;
                        temp[j] = k;
                        if(temp == endWord)
                        {
                            store[temp].insert(curr);
                            endFlag = true;
                        }
                        else if(wordList.find(temp) != wordList.end())
                        {
                            store[temp].insert(curr);
                            if(current.find(temp) == current.end())
                                q.push(temp);
                            current.insert(temp);
                        }
                    }
                }
            }
            for(auto it : current)
            {
                wordList.erase(it);
            }
            current.clear();
        }

        return createSequences(beginWord, endWord);
    }
};
