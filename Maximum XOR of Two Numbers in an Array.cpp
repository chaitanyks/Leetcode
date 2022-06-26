// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// 421. Maximum XOR of Two Numbers in an Array

class Trie {
public:
    Trie * ch[2];
    bool isEnd;
    
    Trie()
    {
        ch[0] = NULL;
        ch[1] = NULL;
        isEnd = false;
    }
    
    void add(string str){
        Trie *temp = this;
        int Len = str.length();
        for(int i=0;i<Len;i++)
        {
            int index = str[i] - '0';
            if(temp->ch[index]==NULL)
                temp->ch[index] = new Trie();
            temp = temp->ch[index];
        }
        temp->isEnd = true;
    }
    
    int find(string str){
        Trie * temp = this;
        string ans = "";
        int Len = str.length();
        for(int i=0;i<Len;i++)
        {
            // int index = str[i] - '0';
            if(str[i]=='1')
            {
                if(temp->ch[0]!=NULL)
                {
                    temp = temp->ch[0];
                    ans = ans + '0';
                }
                else
                {
                    temp = temp->ch[1];
                    ans = ans + '1';
                }
            }
            else
            {
                if(temp->ch[1]!=NULL)
                {
                    temp = temp->ch[1];
                    ans = ans + '1';
                }
                else
                {
                    temp = temp->ch[0];
                    ans = ans + '0';
                }
            }
        }
        int digit = 0;
        int p=0;
        for(int i=ans.length()-1;i>=0;i--)
        {
            digit = digit + (ans[i]-'0') * pow(2,p);
            p++;
        }
        // cout<<ans<<" "<<digit<<endl;
        return digit;
    }
};

class Solution {
public:
    string binary(int temp,int Len){
        string str = "";
        while(temp)
        {
            int rem = temp%2;
            char c = temp%2?'1':'0';
            str = c + str; 
            temp = temp/2;
        }
        int l = str.length();
        while(l!=Len) {
            str = '0' + str;
            l++;
        }
        return str;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 0;
        int mx = nums[0];
        Trie t;
        for(int i=0;i<n;i++)
        {
            mx = max(mx,nums[i]);
        }
        
        int Len = log2(mx) + 1;
        for(int i=0;i<n;i++)
        {
            int val = nums[i];
            string str = binary(val,Len);
            t.add(str);
            // cout<<binary(nums[i],Len)<<endl;
        }
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int val = nums[i];
            string str = binary(val,Len);
            val = t.find(str);
            ans = max(ans,val^nums[i]);
        }
        
        return ans;
    }
};
