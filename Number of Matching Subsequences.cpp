// https://leetcode.com/problems/number-of-matching-subsequences/
// 792. Number of Matching Subsequences

class Trie {
public:
    Trie * character[26];
    
    Trie() {
        for(int i=0;i<26;i++)
            this->character[i] = NULL;
    }
    
    void add(string str)
    {
        Trie * temp = this;
        for(int i=0;i<str.length();i++)
        {
            int index = str[i] -'a';
            if(temp->character[index] == NULL)
                temp->character[index] = new Trie();
            temp = temp->character[index];
        }
    }
    
    bool find(string str)
    {
        Trie * temp = this;
        for(int i=0;i<str.length();i++)
        {
            int index = str[i] -'a';
            if(temp->character[index]==NULL)
                return false;
            temp = temp->character[index];
        }
        return true;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie trie;
        int ans = 0;
        map<string,bool> mp;
        
        for(int i=0;i<words.size();i++)
        {
            string str = words[i];
            if(mp.find(str) != mp.end())
            {
                if(mp[str])
                    ans++;
                continue;
            }
            
            if(trie.find(str))
            {
                mp[str] = true;
                ans++;
            }
            else
            {
                string match = "";
                int index = 0;
                for(int j=0;j<s.length()&&index<str.length();j++)
                {
                    if(s[j]==str[index]) {
                        match = match + str[index];
                        index++;                        
                    }
                }
                
                trie.add(match);
                mp[match] = true;
                
                if(match == str){
                    ans++;
                    mp[str] = true;
                }
                else
                    mp[str] = false;
            }
        }
        return ans;
    }
};
