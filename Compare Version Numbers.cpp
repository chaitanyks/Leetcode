// https://leetcode.com/problems/compare-version-numbers/
// 165. Compare Version Numbers

class Solution {
public:
    vector<int> number(string v) {
        vector<int> version;
        string temp = "";
        int n = v.length();
        
        bool zero = true;
        
        for(int i=0;i<n;i++)
        {
            if(v[i]=='0'&&zero)
                continue;
            
            if(v[i]=='.'){
                if(temp.length()!=0)
                    version.push_back(stoi(temp));
                else
                    version.push_back(0);
                temp = "";
                zero = true;
            }            
            else
            {
                zero = false;
                temp = temp+v[i];
            }
        }
        
        if(temp.length()!=0)
            version.push_back(stoi(temp));
        else
            version.push_back(0);
        
        return version;
    }
    
    bool check(vector<int> version,int index) {
        bool find = false;
        int n = version.size();
        for(int i=index;i<n;i++)
            if(version[i]!=0){
                return !find;
            }
        return find;
    }
    
    int compareVersion(string version1, string version2) {
        
        vector<int> v1 = number(version1);
        vector<int> v2 = number(version2);
        
        int n = v1.size();
        int m = v2.size();
        
        for(int i=0;i<min(n,m);i++)
            if(v1[i]!=v2[i])
                return v1[i]<v2[i]?-1:1;
        
        if(n==m)
            return 0;
        
        return m>n? (check(v2,n)?-1:0) : (check(v1,m)?1:0) ;
    }
};
