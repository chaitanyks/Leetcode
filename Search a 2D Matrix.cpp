// https://leetcode.com/problems/search-a-2d-matrix/
// 74. Search a 2D Matrix

class Solution {
public:
    
    bool bs(vector<vector<int>>& matrix, int level, int low,int high,int target) {
        if(low<=high)
        {
            int mid = (low+high)/2;
            
            if(matrix[level][mid] == target)
                return true;
            
            if(matrix[level][mid]>target)
                return bs(matrix,level,low,mid-1,target);
            
            return bs(matrix,level,mid+1,high,target);
        }
        return false;
    }
    
    int level(vector<vector<int>>& matrix, int target, int low,int high, int m)
    {
        if(low<=high)
        {
            int mid = (low+high)/2;
            
            if(low==high)
                return low;
            
            if(matrix[mid][m-1]<target)
                return lev(matrix,target,mid+1,high,m);
            
            return lev(matrix,target,low,mid,m);
        }
        
        return 0;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        return bs(matrix,level(matrix,target,0,n-1,m),0,m-1,target);
        
    }
};
