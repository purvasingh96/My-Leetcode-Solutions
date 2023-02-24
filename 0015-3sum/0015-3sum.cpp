class Solution {
private:
    
    vector<vector<int>> twoPointers(vector<int>& nums){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]!=nums[i-1]){
                
                    int low=i+1, high=n-1;
                    
                    while(low<high){
                        int sum = nums[i] + nums[low]+nums[high];
                        if(sum == 0){
                            res.push_back({nums[i], nums[low], nums[high]});
                            low+=1;
                            high-=1;
                            while(low<high && nums[low] == nums[low-1]){
                                low+=1;
                            }
                        } else if(sum > 0){
                            high-=1;
                        } else {
                            low+=1;
                        }
                    }
                   
            }
        }
        
        return res;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return twoPointers(nums);
    }
};