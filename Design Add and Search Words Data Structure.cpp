// https://leetcode.com/problems/design-add-and-search-words-data-structure/
// 211. Design Add and Search Words Data Structure

class WordDictionary {
public:
    vector<string> adj[26];
    int minLen = INT_MAX;
    WordDictionary() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    bool matching(string word,string dic)
    {
        int ans = true;
        int n = word.length();
        int m = dic.length();
        
        if(n!=m)
            return false;
        else
        {
            for(int i=0;i<n;i++)
            {
                if(word[i]=='.')
                    continue;
                if(word[i]!=dic[i])
                    ans = false;
            }
        }
        return ans;
    }
    void addWord(string word) {
        int m = word.length();
        if(minLen>m)
            minLen = m;
        int index = word[0] - 'a';
        adj[index].push_back(word);
    }
    
    bool search(string word) {
        
        int m = word.length();
        if(m<minLen)
            return false;
        
        bool ans = false;
        if(word[0]=='.')
        {
            for(int index=0;index<26&&!ans;index++)
            {
                for(int i=0;i<adj[index].size()&&!ans;i++)
                {
                    string dic = adj[index][i];
                    ans = matching(word,dic);
                }
            }
        }
        else
        {
            int index = word[0] - 'a';
            for(int i=0;i<adj[index].size()&&!ans;i++)
            {
                string dic = adj[index][i];
                ans = matching(word,dic);
            }
        }        
        return ans;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
