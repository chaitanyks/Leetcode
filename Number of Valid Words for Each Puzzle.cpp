class Solution {
public:

    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles) {
        map<char, vector<int>> mp;
        vector<int> ans;

        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            int mask = 0;
            for (int j = 0; j < s.length(); j++) {
                int val = s[j] - 'a';
                mask = mask | 1 << val;
            }
            bool visited[26] = {false};

            for (int j = 0; j < s.length(); j++) {
                int val = s[j] - 'a';
                if (!visited[val]) {
                    mp[s[j]].push_back(mask);
                    visited[val] = true;
                }
            }
            // cout<<mask<<endl;
        }

        // for(int i=0;i<26;i++)
        // {
        //     cout<<mp[i].size()<<endl;
        // }

        // for(int i=0;i<puzzles.size();i++)
        for (auto &puzzle:puzzles) {
            string s = puzzle;

            int mask = 0;
            for (auto &str:s) {
                int val = str - 'a';
                mask = mask | 1 << val;
            }

            int count = 0;
            // char fc = s[0];
            for (auto &value:mp[s[0]]) {
                int prd = mask & value;
                // cout<<prd<<" "<<mask<<" "<<mp[fvalue][j]<<endl;
                if (prd == value)
                    count++;
            }
            ans.push_back(count);
            // cout<<mask<<endl;
        }

        return ans;
    }
};
