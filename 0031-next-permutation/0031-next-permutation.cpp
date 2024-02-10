class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> res;
        bool peak=false;
        int start=-1, end=-1;
        
        for(int i=nums.size()-1;i>=0;i--){
            if(res.size() == 0 || nums[res.back()] <= nums[i]) {
                res.push_back(i);
            } else {
                peak=true;
                int lastIndex=-1;
                
                while(res.size()!=0 && nums[res.back()] > nums[i]){
                    lastIndex = res.back();
                    res.pop_back();
                }
                
                    start = i;
                    end = lastIndex;
                    break;
                
            }
        }
        
        if(!peak){
            // entire series in decreasing order
            sort(nums.begin(), nums.end());
        } else {
            swap(nums[start], nums[end]);
            sort(nums.begin()+start+1, nums.end());
        }
    }
};