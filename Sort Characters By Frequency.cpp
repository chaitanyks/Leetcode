class Solution {
public:
    
    bool static sortbysec(const pair<char,int> &a,const pair<char,int> &b) {
        return (a.second > b.second);
    }
    
    string frequencySort(string s) {
        int cl[26] ={0};
        int cu[26] ={0};
        int cd[10] = {0};
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                cl[s[i]-'a']++;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                cd[s[i]-'0']++;
            }
            else
            {
                cu[s[i]-'A']++;
            }
        }
        vector<pair<char,int>> abc;
        for(int i=0;i<26;i++)
        {
            if(cl[i]!=0)
                abc.push_back({97+i,cl[i]});
            if(cu[i]!=0)
                abc.push_back({65+i,cu[i]});
        }
        for(int i=0;i<10;i++)
        {
            if(cd[i]!=0)
                abc.push_back({48+i,cd[i]});
        }
        sort(abc.begin(),abc.end(), sortbysec);
        string ans;
        for(int i=0;i<abc.size();i++)
        {
            int count = abc[i].second;
            string str(count,abc[i].first);
            ans = ans + str;
            // while(count--)
            //     ans = ans + abc[i].first;
            // cout<<abc[i].first<<" "<<abc[i].second<<endl;
        }     
        
        return ans;
    }
};
