// https://leetcode.com/problems/can-place-flowers/
// 605. Can Place Flowers

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int bedSize = flowerbed.size();
        
        //base case
        if(n==0)
            return true;
        
        if(bedSize==1)
        {
            if(flowerbed[0]==0)
                return true;
            else
                return false;
        }
        
        for(int i=0;i<bedSize;i++)
        {
            if(flowerbed[i]==0 && n>0) {
                if(i<bedSize-1 && i>0 && flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
                else if(i==0 && flowerbed[i+1]==0){
                    flowerbed[i] = 1;
                    n--;
                }                
                else if(i==bedSize-1 && flowerbed[i-1]==0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        
        if(n==0)
            return true;
        return false;
    }
};
