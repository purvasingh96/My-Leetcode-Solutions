class Solution {
public:
    string convertToRange(int left, int right) {
            string range = "";
        
            if(left == right) range += to_string(left);
            else range+= to_string(left) + "->" + to_string(right);
            
            return range;
    }
    
    
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        
        if(nums.size()==0) return res;
        
        else if(nums.size()==1) {
            
            res.push_back(to_string(nums[0]));
            return res;
            
        } 
        
        int left = 0, right=1;
        
        while(left<nums.size()) {
            
            
            while(right< nums.size() && nums[right] ==nums[right-1]+ 1) {
                right+=1;
            }
            
            if(right > nums.size()) {
                
                res.push_back(convertToRange(nums[left], nums.back()));
                return res;
                
            } else {
                
                res.push_back(convertToRange(nums[left], nums[right-1]));
                
            }
            
            left=right;
            right+=1;
            
        }
        
        return res;
        
    }
};