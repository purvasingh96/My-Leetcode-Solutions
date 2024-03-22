class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> res;
        bool found=false;
        int start=-1, end=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(res.size()==0 || nums[res.back()] <= nums[i]){
                res.push_back(i);
            } else {
                found=true;
               while(res.size()!=0 && nums[res.back()] > nums[i]) {
                   end=res.back();
                   res.pop_back();
               }
                start=i;
                break;
            }
        }
        cout<<found;
        if(!found){
            sort(nums.begin(), nums.end());
        } else {
            swap(nums[start], nums[end]);
            sort(nums.begin()+start+1, nums.end());
        }
        
        
    }
};