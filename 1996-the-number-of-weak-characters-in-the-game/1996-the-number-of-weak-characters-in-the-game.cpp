class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end(), [](const vector<int>& a, const vector<int>& b){
           if(a[0]!=b[0])  return a[0] < b[0];
            return a[1] > b[1];
        });
        
        
        int res=0, n = nums.size();
        int max_defense=nums.back()[1];
        
        for(int i=n-1;i>=0;i--){
            if(nums[i][1] < max_defense){
                res+=1;
            }
            
            max_defense = max(max_defense, nums[i][1]);
        }
        
        return res;
    }
};