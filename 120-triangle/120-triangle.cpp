class Solution {
public:
    int minimumTotal(vector<vector<int>>& nums) {
        int m = nums.size();
        vector<int> dp_prev(1, nums[0][0]);
        
        for(int i=1;i<m;i++){
            int s = nums[i].size();
            vector<int> dp_new(s, INT_MAX);
            
            for(int j=0;j<s;j++){
                
               if(j==0){
                   
                   dp_new[j] = dp_prev[j] + nums[i][j];
                   
               } else if(j == nums[i].size()-1){
                   
                   dp_new[j] = dp_prev[j-1] + nums[i][j];
                   
               } else{
                   dp_new[j] = min(dp_prev[j] + nums[i][j], dp_prev[j-1]+nums[i][j]);
               }
                   
                
            }
            
            dp_prev = dp_new;
            
        }
        

        
        return *min_element(dp_prev.begin(), dp_prev.end());
        
    }
};