class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        
        for(int i=0;i<nums.size();i++){
            
            if(temp.size()==0 || temp.back() < nums[i]){
                temp.push_back(nums[i]);
            } else {
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                int pos = it-temp.begin();
                //cout<<"i: "<<i<<"pos: "<<pos<<"\n";
                temp[pos] = nums[i];
            }
            
        }
        
        return temp.size();
        
    }
};