class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> temp;
        vector<int> index;
        
        bool found=false;
        for(int i=nums.size()-1;i>=0;i--){
            if(temp.empty() || temp.back() <= nums[i]){
                temp.push_back(nums[i]);
                index.push_back(i);
            } else{
                auto it = upper_bound(temp.begin(), temp.end(), nums[i]);
                if(it == temp.end()) continue;
                else {
                    int idx = it - temp.begin();
                    
                    int t = temp[idx];
                    nums[index[idx]] = nums[i];
                    nums[i] = t;
                    
                    sort(nums.begin()+i+1, nums.end());
                    found=true;
                    break;
                }
            }
        }
        
        // decreasing order;
        if(!found){
            sort(nums.begin(), nums.end());
        }
    }
};