
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res="";
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){
            
            string sa = to_string(a);
            string sb = to_string(b);
            return sa+sb > sb+sa;
        });
        
        //for(auto x:)
        
        if(nums[0] == 0) return "0";
        
        for(auto x:nums) res+= to_string(x);
        return res;
    }
};