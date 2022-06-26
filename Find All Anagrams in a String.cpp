// https://leetcode.com/problems/find-all-anagrams-in-a-string/
// 438. Find All Anagrams in a String

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> mp(26,0);
        vector<int> ans;
        int n = s.length();
        int m = p.length();
        
        if(n<m)
            return ans;
        
        for(int i=0;i<m;i++)
        {
            int index = p[i]-'a';
            mp[index]++;
        }
        
        int low = 0;
        int high = -1;
        vector<int> temp(26,0);
        bool find = true;
        int index;
        
        while(high<n)
        {
            find = true;
            int len = high - low + 1;
            // cout<<len<<" "<<endl;
            if(len == m)
            {
                //check
                for(int i=low;i<=high;i++)
                {
                    index = s[i] - 'a';
                    if(mp[index]==temp[index])
                        continue;
                    else
                    {
                        find = false;
                        break;
                    }
                }
                
                if(find)
                    ans.push_back(low);
                
                index = s[low]-'a';
                // cout<<low<<" ";
                temp[index]--;
                low++;
                high++;
                index = s[high]-'a';
                // cout<<high<<" "<<endl;
                if(high<n)
                temp[index]++;
            }
            else
            {
                high++;
                int index = s[high] - 'a';
                temp[index]++;
            }
        }
        
        return ans;
    }
};
