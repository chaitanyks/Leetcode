// https://leetcode.com/problems/koko-eating-bananas/
// 875. Koko Eating Bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int ans = 0;
        int high = n-1;
        int low = 0;
        int tans = 0;
        
        while(low<=high)
        {
            int mid = (high+low)/2;
            tans = mid+1;
            
            //cal diff
            for(int i=mid+1;i<n;i++)
            {
                tans = tans + piles[i]/piles[mid];
                if(piles[i]%piles[mid]!=0)
                    tans++;
            }
            // cout<<mid<<" "<<tans<<endl;
            
            if(tans==h||low==high)
            {
                ans = mid;
                break;
            }
            else if(tans>h)                
                low = mid+1;
            else
                high = mid;
        }
         
        int hval = piles[ans];
        int lval = 1;
        
        if(ans>=1)
            lval = piles[ans-1];
        
        while(lval<=hval)
        {
            int mval = (hval+lval)/2;            
            
            tans = ans;
            for(int i=ans;i<n;i++)
            {
                tans = tans + piles[i]/mval;
                if(piles[i]%mval!=0)
                    tans++;
            }
            
            // cout<<mval<<" - "<<tans<<endl;
            
            if(lval==hval)
                break;
            else if(tans>h)                
                lval = mval+1;
            else
                hval = mval;
        }
        return hval;        
    }
};
