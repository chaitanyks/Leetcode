#include <iostream>
using namespace std;

int minSwap(string str)
{
    string temp = str;
    
    int ans = 0;
    
    while(temp.length()!=0)
    {
        // cout<<temp<<endl;
        int l = 0;
        int r = temp.length()-1;
        
        if(l==r)
        {
            temp.erase(temp.begin());
        }
        else if(temp[l] == temp[r])
        {
            temp.erase(temp.begin());
            temp.erase(temp.end()-1);
        }
        else
        {
            int ml = 0;
            int mr = r;
            
            while(ml<=r && temp[ml]!=temp[r])
                ml++;
                
            while(mr>=l && temp[mr]!=temp[l])
                mr--;
            
            // non palindrome check
            if(ml==r && mr==l)
            {
                ans = -1;
                break;
            }
                
            if(ml>(r-mr))
            {
                ans = ans + r-mr;
                temp.erase(temp.begin());
                temp.erase(temp.begin() + mr - 1);
            }
            else
            {
                ans = ans + ml;
                temp.erase(temp.begin()+ml);
                temp.erase(temp.end()-1);
            }
        }
        
        // int leftSwap = 
    }
    return ans;
}

int main() {
	// your code goes here
	string str = "mamad";
	cin>>str;
	cout<<minSwap(str);
	return 0;
}
