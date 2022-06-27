class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int c =0, i=0;
        
        int prev=INT_MIN, prev_prev=INT_MIN;
        if(nums.size()<3) return true;
        nums.push_back(INT_MAX);
        
        while(i+1<nums.size()){
            if(prev==INT_MAX || prev <= nums[i]){
                if(prev==INT_MAX){
                    prev=nums[i];
                } else{
                    prev_prev=prev;
                    prev=nums[i];
                }
                i+=1;
            } else{
                if(c!=0) return false;
                if(prev <= nums[i+1]){
                    c+=1;
                    i+=1;
                    
                } else if(nums[i] <= nums[i+1]){
                    c+=1;
                    prev=prev_prev;
                    
                }
                else return false;
            }
        }
        
        return true;
        
    }
};