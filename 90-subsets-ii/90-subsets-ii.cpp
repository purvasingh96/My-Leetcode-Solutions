class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> res;
        int n = nums.size();
        
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> temp;
            for(int index=0;index<n;index++){
                bool biton = (1<<index) & mask;
                if(biton) temp.push_back(nums[index]);
            }
            sort(temp.begin(), temp.end());
            res.insert(temp);
        }   
        
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};