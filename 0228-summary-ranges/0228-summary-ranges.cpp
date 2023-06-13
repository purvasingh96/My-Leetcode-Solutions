class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string low="null", high="null";
        vector<string> ans;
        
        int i=0, n = nums.size();
        
        while(i<n){
            if(low == "null"){
                low = to_string(nums[i++]);
                
                while(i<n && (long long)nums[i] - (long long)nums[i-1] == 1){
                    high = to_string(nums[i]);
                    i+=1;
                }
                
                string s = "";
                if(high == "null") {
                    s = low;
                } else {
                    s = low + "->" + high;
                }
                
                ans.push_back(s);
                low = "null";
                high = "null";
            }
                
                
        }
        
        return ans;
        
    }
};