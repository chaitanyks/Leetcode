// https://leetcode.com/problems/prefix-and-suffix-search/
// 745. Prefix and Suffix Search

class WordFilter {
public:
    map<string, int> mp;
    
    WordFilter(vector<string>& words) {    
        int n = words.size();
        int m = 0;
        string str1 = "";
        string str2 = "";
        string str = "";
        
        for(int i=n-1;i>=0;i--)
        {            
            if(mp.find(words[i]) != mp.end())
                continue;
            
            mp[words[i]] = i;            
            m = words[i].length();
            str1 = "";
            
            for(int j=0;j<m;j++)
            {
                str1 += words[i][j];
                str2 = "";
                
                for(int k = m-1; k >= 0; k--)
                {
                    str2 = words[i][k] + str2;
                    str = str1 + "/" + str2;
                    
                    if(mp.find(str) == mp.end())
                        mp[str] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string str = prefix + "/" + suffix;
        
        if(mp.find(str)!=mp.end())
            return mp[str];
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
