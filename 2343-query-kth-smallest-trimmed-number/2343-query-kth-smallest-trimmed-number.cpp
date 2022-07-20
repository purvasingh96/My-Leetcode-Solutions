typedef long long ll;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto q:queries){
            
            int ksmallest = q[0];
            int trim = q[1];
            
            vector<pair<string, ll>> temp;
            
            for(int i=0;i<nums.size();i++){
                string x = nums[i].substr(nums[i].length()-trim);
                temp.push_back({x, i});    
            }
            
            sort(temp.begin(), temp.end());
            
            ans.push_back(temp[ksmallest-1].second);
            
        }
        
        return ans;
        
    }
};