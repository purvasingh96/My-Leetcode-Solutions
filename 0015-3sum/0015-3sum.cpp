class Solution {
private:
    void twoSum(vector<int>& nums, int target, int start, set<vector<int>>& res){
        //cout<<"target:: "<<target<<" start: "<<start<<"\n";
        int i=start, j=nums.size()-1;
        while(i<j){
            if(nums[i] + nums[j] == target){
                //cout<<"here";
                
                res.insert({-target, nums[i], nums[j]});
                while(j>i && nums[j] == nums[j-1]){
                    j-=1;
                }
                while(i<j && nums[i] == nums[i+1]){
                    i+=1;
                }
                
                i+=1;
                j-=1;
            }
            else {
                if(nums[i] + nums[j] > target){
                    while(j>i && nums[j] == nums[j-1]){
                        j-=1;
                    }
                    j-=1;
                    
                }
                else if(nums[i] + nums[j] < target){
                    while(i<j && nums[i] == nums[i+1]){
                        i+=1;
                    }
                    i+=1;
                }
            }
            
            
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start=1;
        set<vector<int>> res;
        
        while(start<nums.size()){
            twoSum(nums, -nums[start-1], start, res);
            start+=1;
        }
        
        vector<vector<int>> ans(res.begin(), res.end());
        
        return ans;
    }
};