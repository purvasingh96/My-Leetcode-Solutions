class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> res;
        int start=-1, end=-1;
        bool found=false;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(res.size()==0 || nums[res.back()] <= nums[i]){
                res.push_back(i);
            }
            else {
                while(res.size()!=0 && nums[res.back()] > nums[i]){
                    end = res.back();
                    res.pop_back();
                }
                found = true;
                start = i;
                break;
            }            
        }
        
        if(!found){
            sort(nums.begin(), nums.end());
        } else {
            swap(nums[start], nums[end]);
            sort(nums.begin()+start+1, nums.end());
        }
    }
};