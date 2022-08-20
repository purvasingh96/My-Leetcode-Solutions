class Solution {
private:
    int find(vector<pair<int, int>>& res, int target){
        int minsize=INT_MAX;
        int idx=-1;
        
        for(int i=0;i<res.size();i++){
            if(res[i].first == target){
                if(res[i].second < minsize){
                    minsize=res[i].second;
                    idx=i;
                }
            }
        }
        return idx;
    }
    
public:
    bool isPossible(vector<int>& nums) {
     
        vector<pair<int, int>> res;
        
        for(int i=0;i<nums.size();i++){
            int idx = find(res, nums[i]-1);
            
            if(res.size()==0 || idx==-1) {
                res.push_back({nums[i], 1});
            } else {
                res[idx].first = nums[i];
                res[idx].second+=1;
            }
            
        }
        
        for(int i=0;i<res.size();i++){
            if(res[i].second < 3) return false;
        }
        
        return true;
        
    }
};