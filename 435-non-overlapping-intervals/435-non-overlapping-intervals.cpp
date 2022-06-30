class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b){
            
            return a[1] < b[1];
        });
        
        int count=0;
        
        vector<int> back;
        back = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i][0] < back[1]){
                count+=1;
            } else{
                back = nums[i];
            }
            
        }
        
        return count;
    }
};