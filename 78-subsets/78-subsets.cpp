class Solution {
public:
    void back_track(vector<int> nums, int start, int length, vector<int>& temp, vector<vector<int>>& subsets) {
            
        if(temp.size() == length) {
            subsets.push_back(temp);
            return;
        }
        
        if(start > nums.size()-1) return;
        
        for(int i=start;i<nums.size();i++) {
            
            temp.push_back(nums[i]);
            back_track(nums, i+1, length, temp, subsets);
            temp.pop_back();
            
        }
        
    }
        
        
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> subsets;
        
        for(int length=0;length<=nums.size();length++) {
            
            vector<int> temp;
            back_track(nums, 0, length, temp, subsets);
        }
        
        return subsets;
        
    }
};