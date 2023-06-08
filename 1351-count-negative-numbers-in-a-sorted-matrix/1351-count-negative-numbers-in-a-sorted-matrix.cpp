class Solution {

public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n = grid[0].size();
        int idx=n-1;
        for(auto row:grid){
            while(idx>=0 && row[idx]<0){
                idx--;
            }
            
            count += (n - (idx+1));
        }
        
        return count;
    }
};