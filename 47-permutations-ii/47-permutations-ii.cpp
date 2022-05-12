class Solution {
private:
    void back_track(vector<int>& nums, map<int, int> m, vector<int> temp, vector<vector<int>>& res) {
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        
        for(auto x:m){
            
            if(x.second > 0) {
                temp.push_back(x.first);
                m[x.first] -= 1;
                back_track(nums, m, temp, res);
                m[x.first] += 1;
                temp.pop_back();
            }
            
        }
        
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        map<int, int> m;
        vector<vector<int>> res;
        
        for(auto x:nums){
            m[x]+=1;
        }
        
        back_track(nums, m, temp, res);
        
        return res;
    }
};